SRCS	= ft_printf.c ft_print_chars.c ft_printf_putnbr_base.c 

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CFLAGS	= -Wall -Werror -Wextra -c 

GCC	= gcc

RM	= rm -f

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME} 

all:		${NAME}

clean:		
	${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
