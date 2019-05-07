##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## File that compiles
##

SRC		=	lib/my_getnbr.c	\
			lib/my_nb_to_str.c	\
			lib/my_putchar.c	\
			lib/my_put_nbr.c	\
			lib/my_put_nbr_uint.c	\
			lib/my_put_nbr_base.c	\
			lib/my_putstr.c	\
			lib/my_puttab.c \
			lib/my_putstr_error.c	\
			lib/my_revstr.c	\
			lib/my_strcpy.c	\
			lib/my_strcat.c \
			lib/my_strlen.c	\
			lib/my_atoi.c	\
			lib/my_strlen_delim.c	\
			lib/my_tablen.c	\
			lib/my_str_isnum.c 	\
			lib/my_compare_str.c	\
			lib/my_compute_power_it.c	\
			lib/usable_flags.c	\
			lib/usable_flags2.c	\
			lib/usable_flags3.c	\
			lib/my_printf.c	\
			lib/my_str_to_word_array.c	\

SRC2	=	src/my_rpg.c	\
			src/error_handling.c	\
			src/init_struct.c 	\
			src/init_winsoundvar.c	\
			src/create_obj_or_txt.c	\
			src/event_menu.c		\
			src/display_sprites_menu.c	\
			src/event_game.c 	\
			src/display_sprites_game.c 	\
			src/pause.c	\
			src/map_creator.c \
			src/connector.c \
			src/manage_key.c \
			src/rng_path.c \
			src/room.c \
			src/lib_tab.c \
			src/collision.c \
			src/shoot.c \
			src/settings.c \
			src/create_npc.c \
			src/create_mob.c \
			src/dra.c \
			src/init.c \
			src/free.c \
			src/select_map.c \
			src/inventory.c \
			src/create_object.c \
			src/create_object2.c \
			src/draw2.c \
			src/manage_key2.c \
			src/inventory2.c \
			src/inventory3.c \
			src/event_game2.c \
			src/collision2.c \
			src/shop.c \
			src/shop2.c \
			src/quest_check.c \

CC		=	@gcc

CFLAGS  = 	-w -Werror -Wextra -Wall -g3 -O3

LFLAGS	=	-lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio -lm

OBJ 	= 	$(SRC:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

NAME	=	libmy.a

NAME2	=	my_rpg

all : call $(NAME) $(NAME2) calldone

call :
	@echo "\e[32m\e[1mBuilding\e[0m"
	@echo "\e[93m\e[1m...\e[0m"

calldone :
	@echo "\e[91m\e[1mDone !\e[0m"

$(NAME):	$(OBJ)
		@cp lib/*.h ./src/
		@ar rc $(NAME) $(OBJ)
		@echo "*.o" > lib/.gitignore

$(NAME2):	$(OBJ2)
		$(CC) -o $(NAME2) $(OBJ2) $(LFLAGS) $(CFLAGS) -lncurses -L. -lmy -g3
		@cp src/*.h ./
		@cp lib/*.h ./
		@rm -f *.o
		@echo "*.o" > src/.gitignore

clean:
	@rm -f \#*\#
	@rm -f *.o
	@rm -f *~
	@rm -f lib/*.o
	@rm -f lib/*~
	@rm -f lib/\#*\#
	@rm -f src/*~
	@rm -f src/*.o
	@rm -f src/\#*\#

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@rm -f *.h

re: 	fclean all