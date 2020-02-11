/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:13:39 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 18:59:40 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_obj
{
	char *id;
	char **content;
	struct s_obj *next;
}				t_obj;

t_obj	*scene_reader(char *scene);
int check_input_errors(t_obj *lst);
bool check_required_objs(t_obj *lst);

int	res_error(t_obj *res_obj);
int amb_error(t_obj *amb_obj);
int light_error(t_obj *light_obj);
int camera_error(t_obj *cam_obj);
int sphere_error(t_obj *sp_obj);
int square_error(t_obj *sp_obj);
int cylinder_error(t_obj *cy_obj);
int triangle_error(t_obj *tr_obj);
int plane_error(t_obj *pl_obj);

int colors_error(char *colors);
int	coords_error(char *coords);
int bright_error(char *bright);
int vector_error(char *vector);
int prop_error(char *prop);


# endif
