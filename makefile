# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 19:15:09 by danrodri          #+#    #+#              #
#    Updated: 2020/02/03 21:05:30 by danrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean re bonus		

SRCS			= prototipo.c \
			  	scene_reader.c

SRCS_DIR		= srcs/

OBJS			= $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))

OBJS_DIR		= objs/

NAME			= miniRT

GCC				= gcc -Wall -Werror -Wextra

LIB				= ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -lz

RM				= rm -f

RMDIR			= rm -rf

$(NAME):		$(OBJS)
				make -C libft
				$(GCC) -o $(NAME) $(OBJS) $(LIB)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@$(GCC) -c $<
				@mkdir -p $(OBJS_DIR)
				@mv $(@F) $(OBJS_DIR)

clean:		
				$(RM) $(OBJS)
				make clean -C libft 

fclean:			clean
				$(RM) $(NAME)	
