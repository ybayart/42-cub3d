DIRSRC		= ./srcs/
DIRINC		= ./includes/
DIROBJ		= ./objs/
DIRLIB		= ./libft/
DIRMLX		= ./minilibx/
DIRBMP		= ./libbmp/
DIRUTIL		= ./utils/
DIRPARS		= ./parsing/
DIRREND		= ./rendering/
HEAD		= ./includes/

SRCUTIL		=	main \
				print_error \
				updstate \
				next_map \
				free \
				bmp \
				endofprog
				
SRCPARS		=	init \
				test_args \
				open_map \
				open_textures \
				parse_map \
				parse_map_opts \
				parse_map_matrix \
				verif_map \
				error_msg \
				display_info

SRCREND		=	img \
				color \
				draw \
				draw_get_dist \
				draw_extern \
				hooks \
				hook_move \
				hook_vision \
				hud_cross \
				hud_minimap \
				hud_life \
				start_mlx \

SRC			=	$(addprefix ${DIRUTIL}, ${SRCUTIL}) \
				$(addprefix ${DIRPARS}, ${SRCPARS}) \
				$(addprefix ${DIRREND}, ${SRCREND})

SRCS		= $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

SAN 		= -fsanitize=leak

OBJS		= ${SRCS:.c=.o}

NAME		= Cub3D
NAMELFT		= libft.a
NAMEMLX		= libmlx.a
NAMEBMP		= libbmp.a

CC			= gcc
RM			= rm -f

CFLAGS		= -lft -lmlx -lbmp -lm -lbsd -lX11 -lXext

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} -I${DIRMLX} -I${DIRLIB} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd ${DIRLIB} && ${MAKE}
			cd ${DIRMLX} && ${MAKE}
			cd ${DIRBMP} && ${MAKE}
			${CC} -o ${NAME} -I ${DIRINC} -I${DIRMLX} ${OBJS} -L${DIRLIB} -L${DIRMLX} -L${DIRBMP} ${CFLAGS}

main:		$(NAME)
			${CC} ${NAME} main.c

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

ffclean:	fclean
			cd ${DIRLIB} && ${MAKE} fclean
			cd ${DIRMLX} && ${MAKE} clean
			cd ${DIRBMP} && ${MAKE} fclean

ext:
			cd ${DIRLIB} && ${MAKE} re
			cd ${DIRMLX} && ${MAKE} re

re:			fclean all

.PHONY:		all clean fclean re
