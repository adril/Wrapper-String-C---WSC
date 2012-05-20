NAME		=	WStringC_exemple

SRC		=	main.c\
			WStringC.c\
			WSCsplit.c\
			WSCappend.c

INC		=	-I. -I./include/

OBJ		=	$(SRC:.c=.o)
CC		=	clang
CFLAGS          =       -Wimplicit-function-declaration -pedantic
CDEBUG          =       -g -ggdb
RM		=	rm -Rf
ECHO		=	echo -e

$(NAME)		:	$(OBJ)
			@$(CC) $(INC) $(CFLAGS) -o $(NAME) $(OBJ)
			@$(ECHO) '\033[0;32m> Compiled\033[0m'

clean		:
			-@$(RM) $(OBJ)
			-@$(RM) *~
			-@$(RM) \#*\#
			@$(ECHO) '\033[0;35m> Directory cleaned\033[0m'

all		:	$(NAME)

fclean		:	clean
			-@$(RM) $(NAME)
			@$(ECHO) '\033[0;35m> Remove executable\033[0m'

re		:	fclean all

debug		:	$(OBJ)
			@$(CC) $(INC) $(CDEBUG) -o $(NAME) $(OBJ)
			@$(ECHO) '\033[0;32m> Mode Debug: done\033[0m'

.PHONY		:	all clean re fclean debug

.c.o		:	
			$(CC) $(INC) $(CFLAGS) -o $@ -c $<
