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
			array_to_color.c \
			array_to_vector.c \
			array_to_float.c \
			color_check.c \
			coord_check.c \
			dim_check.c \
			light_check.c \
			vector_check.c

VECTOR_SRCS	= vector_operations.c \
			more_vector_operations.c \
			matrix_operations.c \
			matrix_obj2world.c

WINDOW_SRCS	= img_to_window.c \
		  	window_change_cam.c \
			window_key_options.c \
			window_generate_images.c

UTILS_SRCS	= delete_olst.c \
		  	export_to_bmp.c \
			rt_failure.c \
			utils.c

RT_SRCS		= ray_tracer.c \
			pixel_color.c \
			lightning_loops.c \
			collision_cylinder.c \
			collision_plane.c \
			collision_sphere.c \
			collision_square.c \
			collision_triangle.c \
			collision_loops.c

NAME		= miniRT

SRCSDIR		= srcs/

PARSERDIR	= srcs/parser/

COLDIR		= srcs/collisions/

VECTORDIR	= srcs/vector/

WINDOWDIR	= srcs/window/

UTILSDIR	= srcs/utils/

RTDIR		= srcs/raytracer/

OBJSDIR		= objs/

LIB			= -lft -Llibft

MLXLIB_MAC	= -lmlx -L. -framework OpenGL -framework AppKit -lz

MLXLIB_LIN	= -lmlx -L./minilibx -lm -lXext -lX11

MLX			= libmlx.dylib

INCDIR		= includes/

OS		:= $(shell uname)

OBJS		= $(patsubst %.c, $(OBJSDIR)%.o, $(SRCS))

PARSER_OBJS	= $(patsubst %.c, $(OBJSDIR)%.o, $(PARSER_SRCS))

VECTOR_OBJS	= $(patsubst %.c, $(OBJSDIR)%.o, $(VECTOR_SRCS))

WINDOW_OBJS	= $(patsubst %.c, $(OBJSDIR)%.o, $(WINDOW_SRCS))

UTILS_OBJS	= $(patsubst %.c, $(OBJSDIR)%.o, $(UTILS_SRCS))

RT_OBJS	= $(patsubst %.c, $(OBJSDIR)%.o, $(RT_SRCS))

ALL_OBJS	= $(OBJS) $(PARSER_OBJS) $(COL_OBJS) $(VECTOR_OBJS) $(WINDOW_OBJS) $(UTILS_OBJS) $(RT_OBJS)

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

$(OBJSDIR)%.o:  $(PARSERDIR)%.c
			@$(GCC) -c $< -I $(INCDIR)
			@mkdir -p objs
			@mv $(@F) $(OBJSDIR)

$(OBJSDIR)%.o:  $(VECTORDIR)%.c
			@$(GCC) -c $< -I $(INCDIR)
			@mkdir -p objs
			@mv $(@F) $(OBJSDIR)

$(OBJSDIR)%.o:  $(WINDOWDIR)%.c
			@$(GCC) -c $< -I $(INCDIR)
			@mkdir -p objs
			@mv $(@F) $(OBJSDIR)

$(OBJSDIR)%.o:  $(UTILSDIR)%.c
			@$(GCC) -c $< -I $(INCDIR)
			@mkdir -p objs
			@mv $(@F) $(OBJSDIR)

$(OBJSDIR)%.o:  $(RTDIR)%.c
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


debug:		$(OBJS) $(PARSER_OBJS) $(COL_OBJS)
			@make -C libft
			@gcc -g -o $(NAME) $(OBJS) $(PARSER_OBJS) $(COL_OBJS) $(LIB) $(MLXLIB)
