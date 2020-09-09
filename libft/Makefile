# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 15:49:46 by danrodri          #+#    #+#              #
#    Updated: 2020/01/15 14:39:28 by danrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean re

NAME			= libft.a

SRCS			= ft_memset.c \
		 	 	ft_bzero.c \
				ft_calloc.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strmapi.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_lltoa_base.c \
				get_next_line.c \
				ft_lstnew_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstlast_bonus.c


SRCS_DIR		= srcs/

OBJS_DIR		= objs/

INC_DIR			= includes/

OBJS			= $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))

RM			= rm -f

PRINTF_LIB		= libftprintf.a

CFLAGS			= -Wall -Werror -Wextra

$(NAME):		$(OBJS)
			@ar rc $(NAME) $(OBJS)
			@make -C ft_printf
			@mv ft_printf/$(PRINTF_LIB) ./$(NAME)

all:			$(NAME)

$(OBJS_DIR)%.o:		$(SRCS_DIR)%.c
			@mkdir -p $(OBJS_DIR)
			@gcc $(CFLAGS) -c -I $(INC_DIR) $<
			@mv -f $(@F) $(OBJS_DIR)

clean:
			@make clean -C ft_printf
			@$(RMDIR) $(OBJS_DIR)

fclean:			clean
			@make fclean -C ft_printf
			@$(RM) $(NAME)

re:			fclean all

