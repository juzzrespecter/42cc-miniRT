/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:13:39 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/05 19:24:32 by danrodri         ###   ########.fr       */
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
#define ROUND_ERR 1e-6

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	int res_x;
	int res_y;
}				t_data;

typedef struct s_r
{
	int res_x;
	int res_y;
} t_r;

typedef struct s_c
{
	float coord[3];
	float view[3];
	unsigned char fov;
	struct s_c *next;
} t_c;

typedef struct s_l
{
	float coord[3];
	float bright;
	unsigned char l_color[3];
	struct s_l *next;
} t_l;

typedef struct s_a
{
	float bright;
	unsigned char a_color[3];
} t_a;

typedef struct s_sp
{
	float coord[3];
	float d;
	unsigned char color[3];
	struct s_sp *next;
} t_sp;

typedef struct s_pl
{
	float coord[3];
	float v_norm[3];
	unsigned char color[3];
	struct s_pl *next;
} t_pl;

typedef struct s_sq
{
	float coord[3];
	float v_norm[3];
	float size;
	unsigned char color[3];
	struct s_sq *next;
} t_sq;

typedef struct s_cy
{
	float coord[3];
	float v_norm[3];
	float d;
	float h;
	unsigned char color[3];
	struct s_cy *next;
} t_cy;

typedef struct s_tr
{
	float p1[3];
	float p2[3];
	float p3[3];
	unsigned char color[3];
	struct s_tr *next;
} t_tr;

typedef struct s_lst
{
	t_r *res;
	t_a *amb;
	t_c *c_lst;
	t_l *l_lst;
	t_sp *sp_lst;
	t_sq *sq_lst;
	t_pl *pl_lst;
	t_cy *cy_lst;
	t_tr *tr_lst;
} t_lst;

typedef struct s_3dvec
{
	float orig[3];
	float dir[3];
} t_3dvec;

typedef struct s_point
{
	float *p_coord;
	unsigned int color;
	struct s_point *next;
} t_point;



bool scene_parser(char *scene, t_lst *obj_lst);
char *pixel_loop(t_data *data, t_lst *obj_lst);
t_point *search_for_collision(t_lst *obj_lst, float *pixel, float *cam_orig);
unsigned int rgb_conv(unsigned char *rgb_color);

bool colors_err(char *colors);
bool bright_err(char *bright);
bool coords_err(char *coords);
bool prop_err(char *prop);
bool vector_err(char *vector);

bool build_amb(char **content, t_lst *obj_lst);
bool build_res(char **content, t_lst *obj_lst);
bool build_cam(char **content, t_lst *obj_lst);
bool build_tr(char **content, t_lst *obj_lst);
bool build_sq(char **content, t_lst *obj_lst);
bool build_sp(char **content, t_lst *obj_lst);
bool build_cy(char **content, t_lst *obj_lst);
bool build_pl(char **content, t_lst *obj_lst);
bool build_l(char **content, t_lst *obj_lst);

void init_lst(t_lst *obj_lst);
//void destroy_lst(t_lst *obj_lst);

float bright_str_to_f(char *br_str);
void coord_str_to_f(char *coord_str, float *coord);
void color_str_to_i(char *color_str, unsigned char *color);
float str_to_f(char *f_str);
float dot_dist(float *p1, float *p2);

t_point *sp_loop(t_sp *sp, t_3dvec *ray, t_point *a_point);
t_point *cy_loop(t_cy *cy, t_3dvec *ray, t_point *a_point);
t_point *tr_loop(t_tr *tr, t_3dvec *ray, t_point *a_point);
t_point *pl_loop(t_pl *pl, t_3dvec *ray, t_point *a_point);
t_point *sq_loop(t_sq *sq, t_3dvec *ray, t_point *a_point);

# endif
