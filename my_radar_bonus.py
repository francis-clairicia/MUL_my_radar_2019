#! /bin/python3

import sys
import os
import curses
import argparse
import subprocess

def get_args():
    parser = argparse.ArgumentParser()
    return parser.parse_args()

def move_cursor(cursor, key, option_list):
    cursor += -1 if key == curses.KEY_UP else 1
    if cursor < 0:
        cursor = len(option_list) - 1
    elif cursor >= len(option_list):
        cursor = 0
    return cursor

def main(stdscr):
    curses.noecho()
    curses.cbreak()
    curses.curs_set(False)
    stdscr.keypad(True)
    stdscr.timeout(50)
    cursor = 0
    loop = True
    while loop:
        while True:
            script_list = [script[:-4] for script in os.listdir("./scripts") if script.endswith(".rdr")]
            script_list.sort()
            stdscr.clear()
            stdscr.addstr(0, 0, "Welcome to the radar simulator 'My Radar'")
            stdscr.addstr(1, 0, "Choose a script file:")
            for i, script in enumerate(script_list):
                j = i + 2
                stdscr.addstr(j, 0, ">" if i == cursor else " ")
                stdscr.addstr(j, 2, script)
                last_line = j
            stdscr.addstr(last_line + 1, 0, "or press Q to quit")
            stdscr.refresh()
            key = stdscr.getch()
            if key in [curses.KEY_ENTER, 10, 13]:
                break
            if key == ord('q'):
                loop = False
                break
            if key in [curses.KEY_UP, curses.KEY_DOWN]:
                cursor = move_cursor(cursor, key, script_list)
        if loop:
            cmd = f"./my_radar ./scripts/{script_list[cursor]}.rdr"
            output_process = subprocess.run(cmd.split(), capture_output=True)
            stdscr.addstr(last_line + 1, 0, "                  ")
            stdscr.addstr(cursor + 2, 0, " ")
            stdscr.addstr(last_line + 2, 0, "Exit status: {}".format(output_process.returncode))
            output = output_process.stdout.decode()
            stdscr.addstr(last_line + 3, 0, "Output:")
            i = 0
            for i, line in enumerate(output.splitlines()):
                stdscr.addstr(last_line + i + 3, 0, line)
            stdscr.addstr(last_line + i + 5, 0, "Press Enter to return")
            stdscr.addstr(last_line + i + 6, 0, "Press Q to quit")
            key = 0
            while key not in [curses.KEY_ENTER, 10, 13]:
                key = stdscr.getch()
                if key == ord('q'):
                    loop = False
                    break

if __name__ == "__main__":
    get_args()
    curses.wrapper(main)
    sys.exit(0)