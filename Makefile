#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 16:20:58 by danrodri          #+#    #+#              #
#    Updated: 2020/09/30 19:46:32 by danrodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY		= all re clean fclean

SRCS		= main.c

SRCS_DIR	= srcs/

OBJS_DIR	= objs/

OBJS		= $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))

PARSER_SRCS	=	build_amb.c \
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


PARSER_DIR	=	$(SRCS_DIR)parser/

PARSER_OBJS	= $(patsubst %.c, $(OBJS_DIR)%.o, $(PARSER_SRCS))

VECTOR_SRCS	=	vector_operations.c \
			  	more_vector_operations.c \
			  	matrix_operations.c

VECTOR_DIR	=	$(SRCS_DIR)vector/

VECTOR_OBJS	= $(patsubst %.c, $(OBJS_DIR)%.o, $(VECTOR_SRCS))

WINDOW_SRCS	=	img_to_window.c \
			 	window_change_cam.c \
			  	window_key_options.c \
			  	window_generate_images.c

WINDOW_DIR	=	$(SRCS_DIR)window/	

WINDOW_OBJS	= $(patsubst %.c, $(OBJS_DIR)%.o, $(WINDOW_SRCS))

UTILS_SRCS	=	delete_olst.c \
			  	exit_success.c \
				export_to_bmp.c \
			  	exit_failure.c \
				utils.c

UTILS_DIR	=	$(SRCS_DIR)utils/

UTILS_OBJS	= $(patsubst %.c, $(OBJS_DIR)%.o, $(UTILS_SRCS))

RT_SRCS		=	ray_tracer.c \
			  pixel_color.c \
			  lightning_loops.c \
			  collision_cylinder.c \
			  collision_plane.c \
			  collision_sphere.c \
			  collision_square.c \
			  collision_triangle.c \
			  collision_loops.c

RT_DIR		=	$(SRCS_DIR)raytracer/

RT_OBJS		= $(patsubst %.c, $(OBJS_DIR)%.o, $(RT_SRCS))

NAME		= miniRT

LFLAGS		= -lft -Llibft

CC		= gcc -Wall -Werror -Wextra -g -fsanitize=address
CFLAGS		= -Wall -Werror -Wextra

OS       = $(shell uname -s)
MLXDIR   =
MLX      =
ifeq ($(OS), Darwin)
	LFLAGS   += -lmlx -L. -framework OpenGL -framework AppKit -lz
	CFLAGS   += -D MLX_MAC=true
	MLXDIR   = mlx_mac
	MLX	 = libmlx.dylib
else
ifeq ($(OS), Linux)
	LFLAGS   += -lmlx -L. -lXext -lX11 -lm
	CFLAGS   += -D MLX_LIN=true
	MLXDIR   = mlx_lin
	MLX	 = libmlx.a
else
	$(error No MLX available for this architecture)
endif
endif

INC_DIR		= includes/

ALL_OBJS	= $(OBJS) $(PARSER_OBJS) $(VECTOR_OBJS) $(WINDOW_OBJS) $(UTILS_OBJS) $(RT_OBJS)

all:		$(NAME)

$(NAME):	$(ALL_OBJS)
			@make -C libft
			@make -C $(MLXDIR)
			mv ./$(MLXDIR)/$(MLX) .
			$(CC) $(CFLAGS) -o $(NAME) $(ALL_OBJS) $(LFLAGS) $(MLX)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c	
				@$(CC) $(CFLAGS) -c $< -I$(INC_DIR)
				@mkdir -p $(OBJS_DIR)
				@mv $(@F) $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(PARSER_DIR)%.c	
				@$(CC) $(CFLAGS) -c $< -I$(INC_DIR)
				@mkdir -p $(OBJS_DIR)
				@mv $(@F) $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(VECTOR_DIR)%.c	
				@$(CC) $(CFLAGS) -c $< -I$(INC_DIR)
				@mkdir -p $(OBJS_DIR)
				@mv $(@F) $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(UTILS_DIR)%.c	
				@$(CC) $(CFLAGS) -c $< -I$(INC_DIR)
				@mkdir -p $(OBJS_DIR)
				@mv $(@F) $(OBJS_DIR)

$(OBJS_DIR)%.o:	srcs/window/%.c	
				@$(CC) $(CFLAGS) -c $< -I$(INC_DIR)
				@mkdir -p $(OBJS_DIR)
				@mv $(@F) $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(RT_DIR)%.c	
				@$(CC) $(CFLAGS) -c $< -I$(INC_DIR)
				@mkdir -p $(OBJS_DIR)
				@mv $(@F) $(OBJS_DIR)

clean:
			@rm -rf $(OBJS_DIR)
			@make clean -C libft
			@make clean -C $(MLXDIR)

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C libft
			@rm -f $(MLX)

re:			fclean all

