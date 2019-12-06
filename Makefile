##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MAIN		=	main.c

SRC_DIR		=	src

SRC_NO_TEST	=	$(SRC_DIR)/my_radar.c

SRC_TEST	=	$(SRC_DIR)/error_script.c

CSFML		=	csfml/framebuffer.c				\
				csfml/create_window.c			\
				csfml/put_pixel.c				\
				csfml/draw_square.c				\
				csfml/clock.c					\
				csfml/object/create_object.c	\
				csfml/object/animate_object.c	\
				csfml/object/resize_object.c	\
				csfml/object/move_object.c		\
				csfml/object/draw_object.c

SRC			=	$(SRC_NO_TEST) $(SRC_TEST) $(CSFML)

CFLAGS		=	-I./include/ -Wall -Wextra

LIB			=	-L./lib -lmy -lcsfml-graphics -lcsfml-system

OBJ			=	$(MAIN:.c=.o) $(SRC:.c=.o)

NAME		=	my_radar

all:	$(NAME)

lib:
	make -s -C ./lib/my

$(NAME):	lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB)
	rm -f $(OBJ)

tests_run:	lib
	@find . -name "*.gc*" -delete
	gcc -o unit_tests $(SRC_TEST) tests/*.c $(LIB) $(CFLAGS) --coverage -lcriterion
	./unit_tests
	rm -f unit_tests test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

debug:	lib
	gcc -g -o $(NAME) $(MAIN) $(SRC) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f unit_tests *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all lib tests_run debug clean fclean re
