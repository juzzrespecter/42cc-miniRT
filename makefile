# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 19:15:09 by danrodri          #+#    #+#              #
#    Updated: 2020/03/01 20:47:40 by danrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean re bonus

SRCS			= prototipo.c \
			  	scene_parser.c \

SRCS_PARSER		= build_amb.c \
				bright_err.c \
				build_cam.c \
				colors_err.c \
				coords_err.c \
				build_cy.c \
				build_pl.c \
				build_l.c \
				prop_err.c \
				build_res.c \
				build_sp.c \
				build_sq.c \
				build_tr.c \
				vector_err.c \
				obj_builder_utils.c

SRCS_DIR		= srcs/

SRCS_PARSER_DIR		= $(SRCS_DIR)parser/

OBJS			= $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))

OBJS_ERROR		= $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS_PARSER))

OBJS_DIR		= objs/

INC_DIR			= includes/

NAME			= miniRT

GCC			= gcc -Wall -Werror -Wextra

LIB			= ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -lz

RM			= rm -f

RMDIR			= rm -rf

all:			$(NAME)

$(NAME):		$(OBJS) $(OBJS_ERROR)
				@make -C libft
				@$(GCC) -o $(NAME) $(OBJS) $(OBJS_ERROR) $(LIB)

$(OBJS_DIR)%.o: 	$(SRCS_DIR)%.c
				@$(GCC) -c $< -I$(INC_DIR)
				@mkdir -p $(OBJS_DIR)
				@mv $(@F) $(OBJS_DIR)

$(OBJS_DIR)%.o:		$(SRCS_PARSER_DIR)%.c
				$(GCC) -c $< -I$(INC_DIR)
				@mkdir -p $(OBJS_DIR)
				@mv $(@F) $(OBJS_DIR)

clean:
				@$(RMDIR) $(OBJS_DIR)
				@make clean -C libft 

fclean:			clean
				@$(RM) $(NAME)

re:			fclean all
