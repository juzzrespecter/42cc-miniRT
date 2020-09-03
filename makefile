#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 16:20:58 by danrodri          #+#    #+#              #
#    Updated: 2020/09/03 17:43:31 by danrodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY		= all re clean fclean

SRCS		= main.c \
			delete_obj_lst.c \
			setup_obj_lst.c \
			light_check.c \
			color_check.c \
			coord_check.c \
			vector_check.c \
			dim_check.c \
			array_char_to_float.c \
			draw_image.c \
			vector_operations.c \
			matrix_operations.c \
			obj_loops.c \
			cam2world_matrix.c \
			obj2world_matrix.c \
			get_pixel_color.c \
			utils.c \
			image_save_bmp.c

PARSER_SRCS	= build_amb.c \
			build_cam.c \
			build_cylinder.c \
			build_light.c \
			build_plane.c \
			build_res.c \
			build_sphere.c \
			build_square.c \
			build_triangle.c \
			scene_parser.c \
			check_scene_array.c \
			greater_length.c \
			char_to_color.c

COL_SRCS	= collision_cylinder.c \
			collision_cylinder_utils.c \
			collision_plane.c \
			collision_searcher.c \
			collision_sphere.c \
			collision_square.c \
			collision_triangle.c \
			collision_utils.c


NAME		= miniRT

SRCSDIR		= srcs/

PARSERDIR	= srcs/parser/

COLDIR		= srcs/collisions/

OBJSDIR		= objs/

LIB			= ./libft/libft.a

MLXLIB_MAC	= -lmlx -framework OpenGL -framework AppKit -lz

MLXLIB_LIN	= minilinx/libmlx.a

INCDIR		= inc/

OBJS		= $(patsubst %.c, $(OBJSDIR)%.o, $(SRCS))

PARSER_OBJS	= $(patsubst %.c, $(OBJSDIR)%.o, $(PARSER_SRCS))

COL_OBJS	= $(patsubst %.c, $(OBJSDIR)%.o, $(COL_SRCS))

GCC		= gcc -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS) $(PARSER_OBJS) $(COL_OBJS)
			@make -C libft
			@$(GCC) -o $(NAME) $(OBJS) $(PARSER_OBJS) $(COL_OBJS) $(LIB) $(MLXLIB_MAC)

$(OBJSDIR)%.o:	$(SRCSDIR)%.c
			@$(GCC) -c $< -I $(INCDIR)
			@mkdir -p objs
			@mv $(@F) $(OBJSDIR)

$(OBJSDIR)%.o:  $(PARSERDIR)%.c
		@$(GCC) -c $< -I $(INCDIR)
		@mkdir -p objs
		@mv $(@F) $(OBJSDIR)

$(OBJSDIR)%.o:  $(COLDIR)%.c
		@$(GCC) -c $< -I $(INCDIR)
		@mkdir -p objs
		@mv $(@F) $(OBJSDIR)


clean:
		@rm -rf $(OBJSDIR)
		@make clean -C libft

fclean:		clean
		@rm -f $(NAME)
		@make fclean -C libft

re:		fclean all

debug: $(OBJS) $(PARSER_OBJS) $(COL_OBJS)
		@make -C libft
		@gcc -g -o $(NAME) $(OBJS) $(PARSER_OBJS) $(COL_OBJS) $(LIB) $(MLXLIB)

