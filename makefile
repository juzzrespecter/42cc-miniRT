#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 16:20:58 by danrodri          #+#    #+#              #
#    Updated: 2020/07/06 18:30:27 by danrodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY		= all re clean fclean

SRCS		= main.c \
			check_syntax_scene.c \
			greater_length.c \
			check_scene_array.c \
			light_check.c \
			color_check.c \
			coord_check.c \
			vector_check.c \
			dim_check.c \
			res_error_check.c \
			a_error_check.c \
			c_error_check.c \
			l_error_check.c \
			sp_error_check.c \
			pl_error_check.c \
			sq_error_check.c \
			cy_error_check.c \
			tr_error_check.c

NAME		= miniRT

SRCSDIR		= srcs/

OBJSDIR		= objs/

LIB		= ./libft/libft.a

MLXLIB		= -lmlx -framework OpenGL -framework AppKit -lz

OBJS		= $(patsubst %.c, $(OBJSDIR)%.o, $(SRCS))

GCC		= gcc -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C libft
		$(GCC) -o $(NAME) $(OBJS) $(LIB) $(MLXLIB)

$(OBJSDIR)%.o:	$(SRCSDIR)%.c
		$(GCC) -c $<
		mkdir -p objs
		mv $(@F) $(OBJSDIR)

clean:
		rm -r $(OBJSDIR)
		make clean -C libft

fclean:		clean
		rm $(NAME)
		make fclean -C libft
