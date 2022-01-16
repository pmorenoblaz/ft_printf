SRCS	= 	ft_printf_chars.c ft_printf_putnbr_base.c ft_printf.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CFLAGS	= -Wall -Werror -Wextra 

GCC	= gcc

RM	= rm -f

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:		
	${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re 
