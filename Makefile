##################################################################################################################
##  PROJECT                                                                                                     ##
##################################################################################################################

   NAME		=	DeathBalls

##################################################################################################################
##  BUILDING / COMMANDS                                                                                         ##
##################################################################################################################

  COMPILER	=	gcc

  RM		=	rm -f
  ECHO		=	/bin/echo -e

  LOGDIR	=	errors/

  INCLUDES	=	-I./include/									\
			-I./ -I./include/pixelaccess -I./include/color \
      -I./include/zbuffer -I./include/response -I./include/game \
      -I./include/enemy -I./include/libprinto

  FLAGS		=	-std=c11 -Wextra -Wall -Werror -g3

  LIBSPATH	=	-L$(HOME)/.froot/lib/

  LIBRARIES	=	-llapin -lsfml-graphics -lsfml-audio -lsfml-window	\
			-lsfml-system -lstdc++ -lm -ldl -lpthread -lgcc_s -lavcall

##################################################################################################################
##  COLORS                                                                                                      ##
##################################################################################################################

  DEFAULT	=	"\033[00m"
  RED 		=	"\033[0;31m"
  GREEN		=	"\033[0;32m"
  ORANGE 	=	"\033[0;33m"
  BLUE		=	"\033[0;34m"
  PURPLE	=	"\033[0;35m"
  CYAN		=	"\033[0;36m"
  LGRAY 	=	"\033[0;37m"
  DGRAY 	=	"\033[1;30m"
  LRED 		=	"\033[1;31m"
  LGREEN	=	"\033[1;32m"
  YELLOW 	=	"\033[1;33m"
  LBLUE 	=	"\033[1;34m"
  LPURPLE 	=	"\033[1;35m"
  LCYAN 	=	"\033[1;36m"
  WHITE 	=	"\033[1;37m"

##################################################################################################################
##  SOURCES                                                                                                     ##
##################################################################################################################

  SRC		=	$(shell find src/ -name "*.c")
  OBJ		=	$(SRC:.c=.o)

  MAIN		=	$(wildcard main/*.c)
  MOBJ		=	$(MAIN:.c=.o)
  TRASH		=	$(shell find . -name "*~") $(shell find src/ -name "*~")

##################################################################################################################
##  COMPILING RULES                                                                                             ##
##################################################################################################################

  all:			FLAGS = -std=c11 -ffast-math -O2
  all:			erase full

  debug:		FLAGS = -std=c11 -W -Werror -Wall -Wextra -g -g3 -ggdb
  debug:		erase full

  full:			init $(MOBJ) $(OBJ)
			@$(COMPILER) $(MOBJ) $(OBJ) -o $(NAME) $(LIBSPATH) $(LIBRARIES)			\
			 2>> $(LOGDIR)/$(NAME) &&							\
			 $(ECHO) $(LCYAN) "[OK]" $(CYAN) $(NAME) $(DEFAULT) ||				\
			 $(ECHO) $(LPURPLE)  "[KO]" $(PURPLE) $(NAME) $(DEFAULT)
			 @$(ECHO) $(YELLOW) "[OK]" $(ORANGE) "./"$(NAME)" to launch the program, may require arguments"

  .c.o:
			@$(eval TRACE="$(addprefix $(LOGDIR), $(subst /,-, $<))")
			@$(COMPILER) $(DEBUGS) $(FLAGS) $(INCLUDES) -c $< -o $@ 2>> $(TRACE) &&		\
			 $(ECHO) $(LGREEN) "[OK]" $(GREEN) $< $(DEFAULT) ||				\
			 $(ECHO) $(LRED)  "[KO]" $(RED) $< $(DEFAULT)
			@find $(TRACE) -size 0 -delete || true

##################################################################################################################
##  MISCELLANOUS RULES                                                                                          ##
##################################################################################################################


  init:
			@$(ECHO) $(LBLUE) "Compiling project" $(DEFAULT)
			@mkdir -p $(LOGDIR)

  clean:
			@$(RM) $(OBJ) &&								\
			 $(ECHO) $(LGREEN) "[OK]" $(GREEN) "Object files deleted" $(DEFAULT) ||		\
			 $(ECHO) $(LRED) "[KO]" $(RED) "Error while deleting object files" $(DEFAULT)
			@$(RM) $(MOBJ) &&								\
			 $(ECHO) $(LGREEN) "[OK]" $(GREEN) "Main object files deleted" $(DEFAULT) ||	\
			 $(ECHO) $(LRED) "[KO]" $(RED) "Error while deleting main object files" $(DEFAULT)
			@$(RM) $(TRASH) &&								\
			 $(ECHO) $(LGREEN) "[OK]" $(GREEN) "Main object files deleted" $(DEFAULT) ||	\
			 $(ECHO) $(LRED) "[KO]" $(RED) "Error while deleting main object files" $(DEFAULT)

  fclean:		clean erase
			@$(RM) $(NAME) &&								\
			 $(ECHO) $(LGREEN) "[OK]" $(GREEN) "Program deleted" $(DEFAULT) ||		\
			 $(ECHO) $(LRED) "[KO]" $(RED) "Error while deleting program" $(DEFAULT)

  re:			fclean
			@$(MAKE) -s all

  re-debug:		fclean
			@$(MAKE) -s debug

  erase:
			@$(RM) -r $(LOGDIR)

##################################################################################################################
##  EXTRA RULES                                                                                                 ##
##################################################################################################################

  .PHONY: $(CUSTLIBS)
