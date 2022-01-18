
NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_eval_format.c ft_type.c\
		   	type/ft_char.c type/ft_string.c type/ft_int.c\
		   	type/ft_int_u.c type/ft_int_x.c type/ft_point.c\
		   	ft_flag.c ft_percent.c ft_wdt.c\
		   	ft_prec.c libft/ft_itoa.c libft/ft_strdup.c\
		   	libft/ft_strlen.c libft/ft_tolower.c

HEADER	=	-I inc/
OBJ		=	${SRCS:%.c=%.o}

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror ${HEADER}

.PHONY:		all clean fclean re bonus

all:		${NAME}

bonus:		${NAME}

${NAME}	:	${OBJ}
			ar rcs ${NAME} $?

%.o : %.c	${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

clean	:
			${RM} ${OBJ}

fclean	:	clean
	${RM} ${NAME}

re		:	fclean all
