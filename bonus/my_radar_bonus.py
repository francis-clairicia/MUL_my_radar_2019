#! /bin/python3

import sys
import os
import argparse
import subprocess
import pygame

BLACK = (0, 0, 0)
YELLOW = (255, 255, 0)

MENU = "Menu"
SCRIPT = "Launch script"
EXIT = "Exit"

class Menu():
    def __init__(self, window):
        self.window = window
        self.cursor = 0
        #Images
        self.logo = pygame.image.load("./bonus/logo.png")
        self.background = pygame.image.load("./bonus/background.png")
        self.arrow = pygame.image.load("./bonus/arrow.png")
        #Font
        #Options list
        self.option_list = [SCRIPT, EXIT]
        self.rect_list = list()

    def draw(self):
        self.rect_list = self.window.draw_choices(self.option_list, self.cursor, 100)

    def move_cursor(self, key):
        self.cursor += -1 if key == pygame.K_UP else 1
        max_value = len(self.option_list) - 1
        if self.cursor < 0:
            self.cursor = max_value
        elif self.cursor > max_value:
            self.cursor = 0

    def mouse_on_option(self, mouse_pos):
        for i, rect in enumerate(self.rect_list):
            if rect.collidepoint(mouse_pos):
                self.cursor = i
                break

    def events(self, event, actual_section):
        if event.type == pygame.QUIT or (event.type == pygame.KEYUP and event.key in [pygame.K_ESCAPE, pygame.K_q]):
            self.window.stop()
        elif event.type == pygame.KEYUP:
            if event.key in [pygame.K_UP, pygame.K_DOWN]:
                self.move_cursor(event.key)
            elif event.key == pygame.K_RETURN:
                return self.option_list[self.cursor]
        elif event.type in [pygame.MOUSEMOTION, pygame.MOUSEBUTTONUP]:
            self.mouse_on_option(event.pos)
            if event.type == pygame.MOUSEBUTTONUP:
                return self.option_list[self.cursor]
        return actual_section

class ScriptLauncher():
    def __init__(self, window):
        self.window = window
        self.cursor = 0
        #Options list
        self.option_list = sorted([script[:-4] for script in os.listdir("./scripts") if script.endswith(".rdr")])
        self.rect_list = list()

    def draw(self):
        self.rect_list = self.window.draw_choices(self.option_list, self.cursor, 60)

    def move_cursor(self, key):
        self.cursor += -1 if key == pygame.K_UP else 1
        max_value = len(self.option_list) - 1
        if self.cursor < 0:
            self.cursor = max_value
        elif self.cursor > max_value:
            self.cursor = 0

    def mouse_on_option(self, mouse_pos):
        for i, rect in enumerate(self.rect_list):
            if rect.collidepoint(mouse_pos):
                self.cursor = i
                break

    def events(self, event, actual_section):
        if event.type == pygame.QUIT or (event.type == pygame.KEYUP and event.key == pygame.K_q):
            self.window.stop()
        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_ESCAPE:
                self.cursor = 0
                return MENU
            if event.key in [pygame.K_UP, pygame.K_DOWN]:
                self.move_cursor(event.key)
            elif event.key == pygame.K_RETURN:
                self.launch_radar()
        elif event.type in [pygame.MOUSEMOTION, pygame.MOUSEBUTTONUP]:
            self.mouse_on_option(event.pos)
            if event.type == pygame.MOUSEBUTTONUP:
                self.launch_radar()
        return actual_section

    def launch_radar(self):
        cmd = f"./my_radar ./scripts/{self.option_list[self.cursor]}.rdr"
        try:
            output_process = subprocess.run(cmd.split(), check=True, capture_output=True)
        except subprocess.CalledProcessError as e:
            output = [e.output.decode().split(":")[-1][1:-1]]
            status = e.returncode
        else:
            output = output_process.stdout.decode().splitlines()
            status = output_process.returncode
        if len(output) == 0 and status == 0:
            return
        exit_status = self.window.font.render("Exit status: " + str(status), True, YELLOW)
        output_lines = [self.window.font.render(line, True, YELLOW) for line in output]
        done = False
        clock = pygame.time.Clock()
        while not done and not self.window.done:
            clock.tick(30)
            self.window.draw(self.window.background, center=self.window.rect.center)
            self.window.draw(self.window.logo, centerx=self.window.rect.centerx, y=10)
            centerx = self.window.rect.centerx + 200
            rect = self.window.draw(self.window.font.render("Results:", True, YELLOW), centerx=centerx, top=200)
            rect = self.window.draw(exit_status, centerx=centerx, top=rect.bottom + rect.height)
            for line in output_lines:
                rect = self.window.draw(line, centerx=centerx, top=rect.bottom + 10)
            rect = self.window.draw(self.window.font.render("Press Enter to return.", True, YELLOW), centerx=centerx, top=rect.bottom + rect.height)
            self.window.draw(self.window.font.render("Press Q to quit.", True, YELLOW), centerx=centerx, top=rect.bottom + 10)
            pygame.display.flip()
            for event in pygame.event.get():
                if event.type == pygame.QUIT or (event.type == pygame.KEYUP and event.key == pygame.K_q):
                    self.window.stop()
                    done = True
                    break
                if event.type == pygame.KEYUP and event.key == pygame.K_RETURN:
                    done = True
                    break

class Window():
    def __init__(self, width, height):
        self.window = pygame.display.set_mode((width, height))
        self.rect = self.window.get_rect()
        pygame.display.set_caption("My radar")
        self.done = False
        #Images
        self.logo = pygame.image.load("./bonus/logo.png")
        self.background = pygame.image.load("./bonus/background.png")
        self.arrow = pygame.image.load("./bonus/arrow.png")
        #Font
        self.font = None
        #Sections
        self.sections = {
            MENU: Menu(self),
            SCRIPT: ScriptLauncher(self),
            EXIT: None
        }

    def run(self):
        section = MENU
        clock = pygame.time.Clock()
        while not self.done:
            clock.tick(30)
            if self.sections[section] is None:
                break
            self.sections[section].draw()
            pygame.display.flip()
            for event in pygame.event.get():
                section = self.sections[section].events(event, section)
                if self.done:
                    break

    def stop(self):
        self.done = True

    def draw(self, surface, **kwargs):
        rect = surface.get_rect(**kwargs)
        self.window.blit(surface, rect)
        return rect

    def draw_choices(self, option_list, cursor, font_size):
        self.font = pygame.font.Font("./fonts/Darks_Calibri_Remix.ttf", font_size)
        surface_list = [self.font.render(option, True, YELLOW) for option in option_list]
        rect_list = list()
        self.draw(self.background, center=self.rect.center)
        self.draw(self.logo, centerx=self.rect.centerx, y=10)
        rect = pygame.rect.Rect(0, 0, 0, 0)
        rect.right = 1200
        rect.bottom = 190
        for i, option in enumerate(surface_list):
            rect = self.draw(option, right=rect.right, top=rect.bottom + 10)
            rect_list.append(rect)
            if i == cursor:
                self.draw(self.arrow, centery=rect.centery, right=rect.left - 10)
        return rect_list.copy()

def get_args():
    parser = argparse.ArgumentParser()
    return parser.parse_args()

if __name__ == "__main__":
    pygame.init()
    get_args()
    os.system("mkdir -p ./scripts")
    Window(1280, 720).run()
    pygame.quit()
    sys.exit(0)