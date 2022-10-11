/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:26:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/03 17:25:52 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "libft.h"
# include "parser.h"
# include "vector.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "window.h"
# include "structs.h"
# include "../minilibx/mlx.h"
# ifndef ERROR
#  define ERROR 1e-6
# endif
# ifndef FILE_HEADER_SIZE
#  define FILE_HEADER_SIZE 14
# endif
# ifndef INFO_HEADER_SIZE
#  define INFO_HEADER_SIZE 40
# endif

void			delete_olst(t_objs *olst);
char			*ray_tracer(t_rt *index, t_cam *cam);
t_point			collision_loops(t_objs *obj_lst, t_ray *ray);
double			ft_max(double a, double b);
double			ft_min(double a, double b);
void			ft_split_free(char **table);
double			collision_sphere(t_sp *sp, t_ray *ray);
double			collision_plane(t_vector normal, t_vector pl_point, t_ray *ray);
double			collision_square(t_sq *sq, t_ray *ray);
double			collision_cylinder(t_cy *cy, t_ray *ray);
double			collision_triangle(t_tr *tr, t_ray *ray);
t_vector		normal_cylinder(t_cy *cy, t_vector point);
t_vector		normal_triangle(t_vector f_p, t_vector s_p, t_vector t_p);
unsigned int	pixel_color(t_objs *obj_lst, t_point *point);
bool			lightning_loops(t_ray *light_ray, t_objs *o_lst, double len);
void			export_to_bmp(t_rt *index, char *rtname);
void			exit_failure(t_rt *index, char *err_msg);
int				exit_success(t_rt *index);

#endif
