##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

FSRC	:=	src/

FINIT	:=	$(FSRC)init/

FSFML	:=	$(FSRC)F_CSFML/

FDESTROY	:=	$(FSRC)destroyer/

FINTRO	:=	$(FSRC)intro/

FMENU	:=	$(FSRC)menu/

FGAME	:=	$(FSRC)gameplay/

FPLAYER	:=	$(FSRC)gameplay/player/

FCREATIVE	:=	$(FSRC)gameplay/creative/

FMAP	:=	$(FSRC)map/

SRC	:=	$(FSRC)main.c			\
		$(FSRC)launch_game.c		\
		$(FSFML)display.c		\
		$(FSFML)set_sprite_pos.c	\
		$(FSFML)text_handling.c		\
		$(FSFML)framebuffer.c		\
		$(FSFML)texture_sprite_handling.c\
		$(FINIT)init_window.c		\
		$(FINIT)init_menu.c		\
		$(FINIT)init_gameplay.c		\
		$(FINIT)init_player.c		\
		$(FINIT)init_clock.c		\
		$(FINIT)init_menu_pause.c	\
		$(FINIT)button_handling.c	\
		$(FINIT)init_intro.c		\
		$(FINIT)init_inventory.c	\
		$(FDESTROY)destroy_win.c	\
		$(FDESTROY)destroy_intro.c	\
		$(FINTRO)intro_0.c		\
		$(FINTRO)intro_1.c		\
		$(FINTRO)get_all_path.c		\
		$(FMENU)menu_0.c		\
		$(FMENU)load_game.c		\
		$(FMENU)settings.c		\
		$(FMENU)new_game.c		\
		$(FGAME)gameplay_0.c		\
		$(FGAME)menu_pause.c		\
		$(FPLAYER)player_event.c	\
		$(FPLAYER)player_mouvement.c	\
		$(FPLAYER)display_player.c	\
		$(FPLAYER)tools_actions.c	\
		$(FPLAYER)hud.c			\
		$(FCREATIVE)creative.c		\
		$(FCREATIVE)creative_event.c	\
		$(FMAP)generate_map.c		\
		$(FMAP)display_map.c		\
		$(FMAP)map_actions.c		\
		$(FMAP)fill_map.c		\
		$(FMAP)generate_caves.c		\
		$(FMAP)handle_day_night.c	\
		$(FMAP)generate_houses.c	\

NAME	:=	my_rpg

OBJ	:=	$(SRC:.c=.o)

_MAKEFILES	:=	my	\

LIBS	:=	$(addprefix -l, $(_MAKEFILES))

LDFLAGS +=	 -L./lib $(LIBS) -lm -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio


CFLAGS	+=	-Wall -Wextra -g -I./include/

COLOR	:=	\033[01;38;5;31m

WHITE	:=	\033[0;0m

CLEAR	:=	\033[2K

all:	$(NAME)

$(NAME):	$(OBJ)	make_all
	@$(CC)  -g $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"

%.o:	%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:	make_clean
	@find ./$(FSRC) -name "*.o" -delete
	@rm -f vgcore*
	@echo -e "'.o' Deletion : \033[01;38;5;220mDONE$(WHITE)"

fclean: clean	make_fclean
	@rm -f $(NAME)
	@echo -e "'$(NAME)' deletion : \033[01;38;5;222mDONE$(WHITE)"

re: fclean all

test: all
	@./$(NAME)

de:	make_all
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -g
	@echo "Valgrind Output :"
	@valgrind ./$(NAME)

go:	all
	@./$(NAME)

make_all:
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C lib/$$makefile;	\
	done

make_clean:
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C lib/$$makefile clean;	\
	done

make_fclean:
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C lib/$$makefile fclean;	\
	done

.PHONY:	$(NAME) clean fclean re go de
