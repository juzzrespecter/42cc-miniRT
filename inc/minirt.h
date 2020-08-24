/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:26:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/24 18:05:42 by danrodri         ###   ########.fr       */
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
#include <mlx.h>

typedef struct s_data
{
	void *mlx_ptr;
	void *img_ptr;
	int x_res;
	int y_res;
	int bits_per_pixel;
	int size_line;
	int endian;
} t_data;

typedef struct s_res
{
	int x_res;
	int y_res;
} t_res;

typedef struct s_amb
{
	float bright;
	unsigned char color[3];
} t_amb;

typedef struct s_cam
{
	float coord[3];
	float normal[3];
	int fov;
	float m_c2w[4][4];
	struct s_cam *next;
} t_cam;

typedef struct s_light
{
	float coord[3];
	float bright;
	unsigned char color[3];
	struct s_light *next;
} t_light;

typedef struct s_sp
{
	float center[3];
	float d;
	unsigned char color[3];
	struct s_sp *next;
} t_sp;

typedef struct s_pl
{
	float coord[3];
	float normal[3];
	unsigned char color[3];
	struct s_pl *next;
} t_pl;

typedef struct s_sq
{
	float center[3];
	float normal[3];
	float side;
	unsigned char color[3];
	struct s_sq *next;
} t_sq;

typedef struct s_cy
{
	float center[3];
	float normal[3];
	float d;
	float h;
	unsigned char color[3];
	struct s_cy *next;
} t_cy;

typedef struct s_tr
{
	float first_point[3];
	float second_point[3];
	float third_point[3];
	unsigned char color[3];
	struct s_tr *next;
} t_tr;

typedef struct s_objlst
{
	t_res *res;
	t_amb *amb;
	t_cam *cam;
	t_light *light;
	t_sp *sp;
	t_pl *pl;
	t_sq *sq;
	t_cy *cy;
	t_tr *tr;
} t_objlst;

t_objlst *scene_parser(char *scene_file);
void setup_obj_lst(t_objlst *obj_lst);
void delete_obj_lst(t_objlst *obj_lst);
int greater_length(char *s1, char *s2);
bool check_scene_array(char **scene_line, int n_lines);
bool res_error_check(char **scene_line);
bool light_check(char *light);
bool color_check(char *color);
bool coord_check(char *coord);
bool vector_check(char *vector);
bool dim_check(char *dim);
float char_to_float(char *array);
void array_char_to_float(float *coord, char *array);
void char_to_color(unsigned char *color, char *array);
bool build_sphere(char **scene_line, t_objlst *obj_lst);
bool build_amb(char **scene_line, t_objlst *obj_lst);
bool build_cylinder(char **scene_line, t_objlst *obj_lst);
bool build_res(char **scene_line, t_objlst *obj_lst);
bool build_triangle(char **scene_line, t_objlst *obj_lst);
bool build_light(char **scene_line, t_objlst *obj_lst);
bool build_cam(char **scene_line, t_objlst *obj_lst);
bool build_plane(char **scene_line, t_objlst *obj_lst);
bool build_square(char **scene_line, t_objlst *obj_lst);
bool build_triangle(char **scene_line, t_objlst *obj_lst);
char *draw_image(t_objlst *obj_lst, t_data data, char *img);
void collision_searcher(t_objlst *obj_lst, t_3dvec *ray);
t_3dvec *sp_loop(t_sp *sp, t_3dvec *ray);
t_3dvec *pl_loop(t_pl *pl, t_3dvec *ray);
t_3dvec *sq_loop(t_sq *sq, t_3dvec *ray);
t_3dvec *cy_loop(t_cy *cy, t_3dvec *ray);
t_3dvec *tr_loop(t_tr *tr, t_3dvec *ray);
double ft_max(double a, double b);
double ft_min(double a, double b);
void point_found(float *p_coord, float *n_vec, unsigned char *p_color, t_3dvec *ray);
bool point_in_plane(float *normal, t_3dvec *ray, float d, float *point);
t_3dvec *collision_sphere(t_sp *sp, t_3dvec *ray);
t_3dvec *collision_plane(t_pl *pl, t_3dvec *ray);
t_3dvec *collision_square(t_sq *sq, t_3dvec *ray);
unsigned int get_pixel_color(t_objlst *obj_lst, t_3dvec *ray);

#endif
