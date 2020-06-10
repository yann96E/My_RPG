##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME    :=      Teraria

CC	:=	gcc
EXT	:=	.c

SOURCE	:=	source/
FSOURCE	:=	main		\
		main_loop	\

CSFML_FCT	:=	$(SOURCE)csfml_fct/
FCSFML_FCT	:=	display				\
			framebuffer			\
			text_handling			\
			texture_sprite_handling		\

DESTROYER	:=	$(SOURCE)destroyer/
FDESTROYER	:=	destroy_intro		\
			destroy_win		\

INITIALISATION	:=	$(SOURCE)initialisation/
FINITIALISATION   :=	button_handling		\
			init_clock		\
			init_gameplay		\
			init_intro		\
			init_inventory		\
			init_menu		\
			init_menu_pause		\
			init_player		\
			init_window		\

SCENE	:=	$(SOURCE)scene/
FSCENE	:=

GAME	:=	$(SCENE)game/
FGAME	:=

GAMEPLAY	:=	$(GAME)gameplay/
FGAMEPLAY	:=	gameplay	\
			menu_pause	\

PLAYER	:=	$(GAMEPLAY)player/
FPLAYER	:=	display_player		\
		hud			\
		player_event		\
		player_mouvement	\
		tools_actions		\

CREATIVE	:=	$(GAMEPLAY)creative/
FCREATIVE	:=	creative		\
			creative_event		\

MAP	:=	$(GAME)map/
FMAP	:=	display_map		\
		fill_map		\
		generate_caves		\
		generate_houses		\
		generate_map		\
		handle_day_night	\
		map_actions		\

INTRO	:=	$(SCENE)intro/
FINTRO	:=	get_all_path	\
		intro_0		\
		intro_1		\

MENU	:=	$(SCENE)menu/
FMENU	:=	menu		\
		new_game	\
		settings	\
		load_game	\

_FILES  :=      $(addprefix $(SOURCE), $(FSOURCE))   			\
                $(addprefix $(CSFML_FCT), $(FCSFML_FCT))   		\
                $(addprefix $(DESTROYER), $(FDESTROYER)) 		\
                $(addprefix $(INITIALISATION), $(FINITIALISATION))	\
                $(addprefix $(SCENE), $(FSCENE)) 			\
                $(addprefix $(GAME), $(FGAME)) 			\
                $(addprefix $(GAMEPLAY), $(FGAMEPLAY)) 		\
                $(addprefix $(CREATIVE), $(FCREATIVE)) 		\
                $(addprefix $(PLAYER), $(FPLAYER)) 			\
                $(addprefix $(MAP), $(FMAP)) 				\
                $(addprefix $(INTRO), $(FINTRO)) 			\
                $(addprefix $(MENU), $(FMENU)) 				\

_FILES_	:=	$(addsuffix $(EXT), $(_FILES))

OBJ     :=      $(_FILES_:$(EXT)=.o)

_MAKEFILES      :=      my		\

LIBNAME	:=	my		\
		printf		\
		bitwise		\
		csfml-graphics  \
		csfml-window 	\
		csfml-system	\
		m		\

LIBS    :=      $(addprefix -l, $(LIBNAME))

LDFLAGS +=      -Llib $(LIBS)

CFLAGS	+=	-I./include -Wall -Wextra -g

COLOR   :=      \033[01;38;5;31m

WHITE   :=      \033[0;0m

CLEAR   :=      \033[2K

all:    $(NAME)

$(NAME):         make_all $(OBJ)
	@$(CC)  $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"
	@echo -e "\033[01;38;5;154m========================== Compiling : Done\033[0;0m"

%.o:    %$(EXT)
	@$(CC) -g -o $@ -c $< $(CFLAGS)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:  make_clean
	@rm -f $(NAME)
	@rm -f vgcore*
	@echo -e "$(NAME) \033[01;38;5;220m'.o' Deletion : DONE$(WHITE)"

fclean: clean   make_fclean
	@rm -f $(OBJ)
	@echo -e "'$(NAME)' \033[01;38;5;222mqdeletion : DONE$(WHITE)"
	@echo -e "\033[01;38;5;154m========================== start Compiling :\033[0;0m"

re:     fclean  all

make_all:
	@for makefile in $(_MAKEFILES); do      \
	$(MAKE) --no-print-directory -C lib/$$makefile; \
	done

make_clean:
	@for makefile in $(_MAKEFILES); do      \
	$(MAKE) --no-print-directory -C lib/$$makefile clean;   \
		done

make_fclean:
	@for makefile in $(_MAKEFILES); do      \
	$(MAKE) --no-print-directory -C lib/$$makefile fclean;  \
		done

run: all
	@./$(NAME)

test: re
	@./$(NAME)

val: re
	@valgrind ./$(NAME)

.PHONY: $(NAME) clean fclean re test
