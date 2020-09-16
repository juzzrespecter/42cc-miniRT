/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:26:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/15 17:18:28 by danrodri         ###   ########.fr       */
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

void		delete_olst(t_objects *olst);
int		greater_length(char *s1, char *s2);
char		*ray_tracer(t_rtindex *index, t_cam *cam);
t_point		*collision_loops(t_objects *obj_lst, t_ray *ray);
double		ft_max(double a, double b);
double		ft_min(double a, double b);
float		*collision_sphere(t_sp *sp, t_ray *ray);
float		*collision_plane(t_pl *pl, t_ray *ray);
float		*collision_square(t_sq *sq, t_ray *ray);
float		*collision_cylinder(t_cy *cy, t_ray *ray);
float		*collision_triangle(t_tr *tr, t_ray *ray);
unsigned int	get_pixel_color(t_objects *obj_lst, t_ray *ray, t_point *point);
void		*export_to_bmp(t_rtindex *index);
void		rt_failure(t_rtindex *index, char *err_msg);

#endif
