/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:26:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/17 19:56:48 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H
#include "libft.h"
#include "parser.h"
#include "vector.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "mlx.h"
#include "window.h"
#include "structs.h"

#ifndef ERROR
# define ERROR 1e-6
#endif

void			delete_olst(t_objects *olst);
char			*ray_tracer(t_rtindex *index, t_cam *cam);
t_point			*collision_loops(t_objects *obj_lst, t_ray *ray);
double			ft_max(double a, double b);
double			ft_min(double a, double b);
float			collision_sphere(t_sp *sp, t_ray *ray);
float			collision_plane(t_vector normal, t_vector pl_point, t_ray *ray);
float			collision_square(t_sq *sq, t_ray *ray);
float			collision_cylinder(t_cy *cy, t_ray *ray);
float			collision_triangle(t_tr *tr, t_ray *ray);
t_vector		normal_cylinder(t_cy *cy, t_vector point);
t_vector		normal_triangle(t_vector f_p, t_vector s_p, t_vector t_p);
unsigned int	get_pixel_color(t_objects *obj_lst, t_point *point);
bool			lightning_loops(t_ray *light_ray, t_objects *o_lst, float len);
void			*export_to_bmp(t_rtindex *index);
void			rt_failure(t_rtindex *index, char *err_msg);

#endif
