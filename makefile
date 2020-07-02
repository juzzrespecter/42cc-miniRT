#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 16:20:58 by danrodri          #+#    #+#              #
#    Updated: 2020/07/02 19:17:35 by danrodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY		= all re clean fclean

SRCS		= main.c \
			check_syntax_scene.c

NAME		= miniRT

SRCSDIR		= srcs/

OBJSDIR		= objs/

LIB		= ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -lz

OBJS		= $(patsubst %.c, $(OBJSDIR)%.o, $(SRCS))

GCC		= gcc -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C libft
		$(GCC) -o $(NAME) $(OBJS) $(LIB)

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
