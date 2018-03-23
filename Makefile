COM_COLOR   = \033[1;34m
CLEAN_COLOR	= \033[1;31m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"
CLEAN_STRING = "Cleaning"

NAME=lem-in
FLAGS= -Wall -Wextra -Werror -I. -c
LIBDIR=libft/
LIB=$(LIBDIR)libft.a
PRINTFDIR=ft_printf/
PRINTF=$(PRINTFDIR)libftprintf.a
HASHTABLEDIR=hashtable/
HASHTABLE=$(HASHTABLEDIR)hashtable.a
SRCS=main.c\
	 src/read/read.c\
	 src/read/parse_room.c\
	 src/read/parse_link.c\
	 src/path/bfs.c\
	 src/path/break.c\
	 src/path/process.c\
	 src/path/combinations.c\
	 src/path/result.c\
	 src/path/init/init.c\
	 src/path/init/funcs.c\
	 src/path/bind/bind.c\
	 src/path/bind/funcs.c\
	 src/path/finish/finish.c\
	 src/path/finish/funcs.c\
	 src/print/print.c\
	 src/print/funcs.c\
	 src/print/del_extra.c\
	 src/errors.c\
	 get_next_line/get_next_line.c
OBJS=$(SRCS:%.c=%.o)

.PHONY: libs all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C $(LIBDIR)
	@make -s -C $(PRINTFDIR)
	@make -s -C $(HASHTABLEDIR)
	@gcc -o $(NAME) $(OBJS) $(LIB) $(PRINTF) $(HASHTABLE)> $@.log; \
        RESULT=$$?; \
        if [ $$RESULT -ne 0 ]; then \
            printf "%-20b%-40b%b" "$(COM_COLOR)$(COM_STRING)" "$(OBJ_COLOR)$(NAME)" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
        elif [ -s $@.log ]; then \
            printf "%-20b%-40b%b" "$(COM_COLOR)$(COM_STRING)" "$(OBJ_COLOR)$(NAME)" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
        else  \
            printf "%-20b%-40b%b" "$(COM_COLOR)$(COM_STRING)" "$(OBJ_COLOR)$(NAME)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
        fi; \
        rm -f $@.log; \
        exit $$RESULT

%.o: %.c
	@gcc $(FLAGS) $< -o $@> $@.log; \
        RESULT=$$?; \
        if [ $$RESULT -ne 0 ]; then \
            printf "%-20b%-40b%b" "$(COM_COLOR)$(COM_STRING)" "$(OBJ_COLOR)$(NAME): $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
        elif [ -s $@.log ]; then \
            printf "%-20b%-40b%b" "$(COM_COLOR)$(COM_STRING)" "$(OBJ_COLOR)$(NAME): $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
        fi; \
        rm -f $@.log; \
        exit $$RESULT

clean:
	@-rm -f $(OBJS)
	@make -C $(LIBDIR) fclean
	@make -C $(PRINTFDIR) fclean
	@make -C $(HASHTABLEDIR) fclean
	@printf "%-20b%b" "$(CLEAN_COLOR)$(CLEAN_STRING)" "$(OBJ_COLOR)lem-in$(NO_COLOR)\n"

fclean: clean
	@-rm -f $(NAME)
	@printf "%-20b%b" "$(CLEAN_COLOR)Removing" "$(OBJ_COLOR)$(NAME)$(NO_COLOR)\n"

re: fclean all
