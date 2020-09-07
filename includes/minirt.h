/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:26:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 20:27:54 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H
#include "../libft/libft.h"
#include "vector.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "structs.h"

t_olst *scene_parser(char *scene_file);
void delete_olst(t_olst *olst);
int greater_length(char *s1, char *s2);
bool check_scene_array(char **scene_line, int n_lines);
bool res_error_check(char **scene_line);
bool light_check(char *light);
bool color_check(char *color);
bool coord_check(char *coord);
bool vector_check(char *vector);
bool dim_check(char *dim);
float array_to_float(char *array);
t_vector array_to_vector(char *array);
t_color array_to_color(char *array);
bool build_sphere(char **scene_line, t_olst *obj_lst);
bool build_amb(char **scene_line, t_olst *obj_lst);
bool build_cylinder(char **scene_line, t_olst *obj_lst);
bool build_res(char **scene_line, t_olst *obj_lst);
bool build_triangle(char **scene_line, t_olst *obj_lst);
bool build_light(char **scene_line, t_olst *obj_lst);
bool build_cam(char **scene_line, t_olst *obj_lst);
bool build_plane(char **scene_line, t_olst *obj_lst);
bool build_square(char **scene_line, t_olst *obj_lst);
bool build_triangle(char **scene_line, t_olst *obj_lst);
char *draw_image(t_olst *obj_lst, t_data *data);
void collision_searcher(t_olst *obj_lst, t_ray *ray);
t_ray *sp_loop(t_sp *sp, t_ray *ray);
t_ray *pl_loop(t_pl *pl, t_ray *ray);
t_ray *sq_loop(t_sq *sq, t_ray *ray);
t_ray *cy_loop(t_cy *cy, t_ray *ray);
t_ray *tr_loop(t_tr *tr, t_ray *ray);
double ft_max(double a, double b);
double ft_min(double a, double b);
void point_found(t_vector p_coord, t_vector n_vec, t_color p_color, t_ray *ray);
bool point_in_plane(t_vector normal, t_vector plane_point, t_ray *ray, t_vector *point);
t_ray *collision_sphere(t_sp *sp, t_ray *ray);
t_ray *collision_plane(t_pl *pl, t_ray *ray);
t_ray *collision_square(t_sq *sq, t_ray *ray);
t_ray *collision_cylinder(t_cy *cy, t_ray *ray);
t_ray *collision_triangle(t_tr *tr, t_ray *ray);
float a_calc(t_vector ray_dir, t_vector axis_dir);
float b_calc(t_vector ray_dir, t_vector axis_dir, t_vector or, t_vector axis_or);
float c_calc(t_vector axis_dir, t_vector or, t_vector axis_or, float r);
unsigned int get_pixel_color(t_olst *obj_lst, t_ray *ray);
void *image_save_bmp(t_data *img_data);

#endif
