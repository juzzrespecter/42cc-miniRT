#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 16:20:58 by danrodri          #+#    #+#              #
#    Updated: 2020/09/29 19:07:51 by danrodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY		= all re clean fclean

SRCS		= main.c \
			parser/build_amb.c \
			parser/build_cam.c \
			parser/build_cylinder.c \
			parser/build_light.c \
			parser/build_plane.c \
			parser/build_res.c \
			parser/build_sphere.c \
			parser/build_square.c \
			parser/build_triangle.c \
			parser/scene_parser.c \
			parser/check_scene_array.c \
			parser/array_to_color.c \
			parser/array_to_vector.c \
			parser/array_to_float.c \
			parser/color_check.c \
			parser/coord_check.c \
			parser/dim_check.c \
			parser/light_check.c \
			parser/vector_check.c
			vector/vector_operations.c \
			vector/more_vector_operations.c \
			vector/matrix_operations.c \
			window/img_to_window.c \
		  	window/window_change_cam.c \
			window/window_key_options.c \
			window/window_generate_images.c
			utils/delete_olst.c \
		  	utils/export_to_bmp.c \
			utils/rt_failure.c \
			utils/utils.c
			raytracer/ray_tracer.c \
			raytracer/pixel_color.c \
			raytracer/lightning_loops.c \
			raytracer/collision_cylinder.c \
			raytracer/collision_plane.c \
			raytracer/collision_sphere.c \
			raytracer/collision_square.c \
			raytracer/collision_triangle.c \
			raytracer/collision_loops.c

NAME		= miniRT

SRCSDIR		= srcs/

OBJSDIR		= objs/

LIB		= -lft -Llibft

MLXLIB_MAC	= -lmlx -L. -framework OpenGL -framework AppKit -lz

MLXLIB_LIN	= -lmlx -L./minilibx -lm -lXext -lX11

MLX		= libmlx.dylib

INCDIR		= includes/

OS		:= $(shell uname)

OBJS		= $(patsubst %.c, $(OBJSDIR)%.o, $(SRCS))

GCC			= gcc -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(ALL_OBJS)
			@make -C libft
			@make -C minilibx
			@mv ./minilibx/$(MLX) .
ifeq ($(OS), Linux)
			@$(GCC) -o $(NAME) $(ALL_OBJS) $(LIB) $(MLXLIB_LIN)
else
			@$(GCC) -o $(NAME) $(ALL_OBJS) $(LIB) $(MLXLIB_MAC)
endif

$(OBJSDIR)%.o:	$(SRCSDIR)%.c
			@$(GCC) -c $< -I $(INCDIR)
			@mkdir -p objs
			@mv $(@F) $(OBJSDIR)

clean:
			@rm -rf $(OBJSDIR)
			@make clean -C libft
			@make clean -C minilibx

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C libft
			@rm -f $(MLX)

re:			fclean all
