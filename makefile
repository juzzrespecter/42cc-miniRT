# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 19:15:09 by danrodri          #+#    #+#              #
#    Updated: 2020/02/11 21:04:35 by danrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean re bonus		

SRCS			= prototipo.c \
			  	scene_reader.c

SRCS_DIR		= srcs/

SRCS_ERRORS		= amb_error.c \
				bright_error.c \
				camera_error.c \
				colors_error.c \
				coord_error.c \
				cylinder_error.c \
				plane_error.c \
				light_error.c \
				prop_error.c \
				res_error.c \
				sphere_error.c \
				square_error.c \
				triangle_error.c \
				vector_error.c \
				check_input_errors.c \
				check_required_objs.c

SRCS_ERRORS_DIR		= $(SRCS_DIR)errors/

OBJS			= $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))

OBJS_ERROR		= $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS_ERRORS))

OBJS_DIR		= objs/

NAME			= miniRT

GCC				= gcc -Wall -Werror -Wextra

LIB				= ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -lz

RM				= rm -f

RMDIR			= rm -rf

all:			$(NAME)

$(NAME):		$(OBJS) $(OBJS_ERROR)
				@make -C libft
				@$(GCC) -o $(NAME) $(OBJS) $(OBJS_ERROR) $(LIB)

$(OBJS_DIR)%.o: 	$(SRCS_DIR)%.c
				@$(GCC) -c $<
				@mkdir -p $(OBJS_DIR)
				@mv $(@F) $(OBJS_DIR)

$(OBJS_DIR)%.o:		$(SRCS_ERRORS_DIR)%.c
				@$(GCC) -c $<
				@mkdir -p $(OBJS_DIR)
				@mv $(@F) $(OBJS_DIR)

clean:
				@$(RMDIR) $(OBJS_DIR)
				@make clean -C libft 

fclean:			clean
				@$(RM) $(NAME)

re:			fclean all
