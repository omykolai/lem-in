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
CLEAN_STRING	 = "Cleaning"

NAME=libft.a
FLAGS= -Wall -Wextra -Werror -I. -c
SRCS=ft_bzero.c\
	 ft_memccpy.c\
	 ft_memchr.c\
	 ft_memcmp.c\
	 ft_memcpy.c\
	 ft_memmove.c\
	 ft_memset.c\
	 ft_strlen.c\
	 ft_strdup.c\
	 ft_strcpy.c\
	 ft_strncpy.c\
	 ft_strcat.c\
	 ft_strncat.c\
	 ft_strlcat.c\
	 ft_strchr.c\
	 ft_strrchr.c\
	 ft_strstr.c\
	 ft_strnstr.c\
	 ft_strcmp.c\
	 ft_strncmp.c\
	 ft_atoi.c\
	 ft_atoimax.c\
	 ft_isalpha.c\
	 ft_isdigit.c\
	 ft_isalnum.c\
	 ft_isascii.c\
	 ft_isprint.c\
	 ft_toupper.c\
	 ft_tolower.c\
	 ft_memalloc.c\
	 ft_memdel.c\
	 ft_strnew.c\
	 ft_strdel.c\
	 ft_strclr.c\
	 ft_striter.c\
	 ft_striteri.c\
	 ft_strmap.c\
	 ft_strmapi.c\
	 ft_strequ.c\
	 ft_strnequ.c\
	 ft_strsub.c\
	 ft_strjoin.c\
	 ft_strtrim.c\
	 ft_strsplit.c\
	 ft_itoa.c\
	 ft_itov.c\
	 ft_putchar.c\
	 ft_putstr.c\
	 ft_putendl.c\
	 ft_putnbr.c\
	 ft_putchar_fd.c\
	 ft_putstr_fd.c\
	 ft_putendl_fd.c\
	 ft_putnbr_fd.c\
	 ft_lstnew.c\
	 ft_lstnewcopy.c\
	 ft_lstdelone.c\
	 ft_lstdel.c\
	 ft_lstadd.c\
	 ft_lstadd_.c\
	 ft_lstiter.c\
	 ft_lstmap.c\
	 ft_lstdelnode.c\
	 ft_lstdelval.c\
	 ft_lstdel_first_match.c\
	 ft_lstfind.c\
	 ft_lstfind_first_match.c\
	 ft_lstdup.c\
	 ft_lstlen.c\
	 ft_lstaddsorted.c\
	 ft_lstappend.c\
	 ft_qnew.c\
	 ft_qpush.c\
	 ft_qpush_.c\
	 ft_qpushcopy.c\
	 ft_qpop.c\
	 ft_qpopnode.c\
	 ft_qdestroy.c\
	 ft_qdup.c\
	 ft_qaddrange.c\
	 ft_qsub.c\
	 ft_itoa_base.c\
	 ft_itoamax.c\
	 ft_uitoamax.c\
	 ft_wstrnew.c\
	 ft_wstrlen.c\
	 ft_divceil.c
OBJS=$(SRCS:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS) && ranlib $(NAME)> $@.log; \
        RESULT=$$?; \
        if [ $$RESULT -ne 0 ]; then \
            printf "%-20b%-40b%b" "$(COM_COLOR)$(COM_STRING)" "$(OBJ_COLOR)libft" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
        elif [ -s $@.log ]; then \
            printf "%-20b%-40b%b" "$(COM_COLOR)$(COM_STRING)" "$(OBJ_COLOR)libft" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
        else  \
            printf "%-20b%-40b%b" "$(COM_COLOR)$(COM_STRING)" "$(OBJ_COLOR)libft" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
        fi; \
        rm -f $@.log; \
        exit $$RESULT

%.o: %.c
	@gcc $(FLAGS) $< -o $@> $@.log; \
        RESULT=$$?; \
        if [ $$RESULT -ne 0 ]; then \
            printf "%-20b%-40b%b" "$(COM_COLOR)$(COM_STRING)" "$(OBJ_COLOR)libft: $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
        elif [ -s $@.log ]; then \
            printf "%-20b%-40b%b" "$(COM_COLOR)$(COM_STRING)" "$(OBJ_COLOR)libft: $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
        fi; \
        rm -f $@.log; \
        exit $$RESULT

clean:
	@-rm -f $(OBJS)
	@printf "%-20b%b" "$(CLEAN_COLOR)$(CLEAN_STRING)" "$(OBJ_COLOR)libft$(NO_COLOR)\n"

fclean: clean
	@-rm -f $(NAME)
	@printf "%-20b%b" "$(CLEAN_COLOR)Removing" "$(OBJ_COLOR)libft.a$(NO_COLOR)\n"

re: fclean all
