DIRSRC		= ./srcs/
DIRINC		= ./includes/
DIROBJ		= ./objs/
DIRLIB		= ./libft/
DIRMLX		= ./minilibx/
HEAD		= ./includes/

SRC			= 	main \
				init \
				test_args \
				print_error \
				open_map \
				parse_map \
				parse_map_opts \
				parse_map_matrix \
				verif_map \
				display_info \
				updstate \
				free \
				error_msg \
				endofprog

SRCS		= $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

SAN 		= -fsanitize=address

OBJS		= ${SRCS:.c=.o}

NAME		= Cub3D
NAMELFT		= libft.a
NAMEMLX		= libmlx.a

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} -I${DIRLIB} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd ${DIRLIB} && ${MAKE}
			cd ${DIRMLX} && ${MAKE}
			${CC} ${CFLAGS} -o ${NAME} -I ${DIRINC} -I ${DIRMLX} -I -L ${DIRMLX}${NAMEMLX} -I -L ${DIRLIB}${NAMELFT} -lmlx -framework OpenGL -framework AppKit ${OBJS}

main:		$(NAME)
			${CC} ${NAME} main.c

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

ext:
			cd ${DIRLIB} && ${MAKE} re
			cd ${DIRMLX} && ${MAKE} re

re:			fclean all

.PHONY:		all clean fclean re
