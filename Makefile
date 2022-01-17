
NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_eval_format.c ft_type.c\
		   	ft_char.c ft_string.c ft_int.c\
		   	ft_int_u.c ft_int_x.c ft_point.c\
		   	ft_flag.c ft_percent.c ft_wdt.c\
		   	ft_prec.c ft_itoa.c ft_strdup.c\
		   	ft_strlen.c ft_tolower.c

HEADER	=	ft_printf.h
OBJ		=	${SRCS:%.c=%.o}

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I${HEADER}

.PHONY:		all clean fclean re bonus

all:		${NAME}

bonus:		${NAME}

${NAME}	:	${OBJ} ${HEADER}
			ar rcs ${NAME} $?

%.o : %.c	${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

clean	:
			${RM} ${OBJ}

fclean	:	clean
	${RM} ${NAME}

re		:	fclean all
