/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:46:48 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/01 21:27:43 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <stdbool.h>

typedef struct			s_vector
{
	double		x;
	double		y;
	double		z;
}						t_vector;

typedef struct			s_matrix
{
	t_vector	a;
	t_vector	b;
	t_vector	c;
}						t_matrix;

typedef struct			s_color
{
	float		r;
	float		g;
	float		b;
}						t_color;

typedef struct			s_ray
{
	t_vector	origin;
	t_vector	dir;
}						t_ray;

typedef struct			s_point
{
	t_vector	coord;
	double		t;
	t_vector	normal;
	t_color		color;

}						t_point;

typedef struct			s_amb
{
	float		bright;
	t_color		color;
}						t_amb;

typedef struct			s_cam
{
	t_vector		coord;
	t_vector		orientation;
	t_matrix		matrix;
	int				fov;
	int				bpp;
	int				sl;
	int				e;
	void			*img_ptr;
	char			*img;
	struct s_cam	*next;
}						t_cam;

typedef struct			s_light
{
	t_vector		coord;
	float			bright;
	t_color			color;
	struct s_light	*next;
}						t_light;

typedef struct			s_sp
{
	t_vector	center;
	float		d;
	t_color		color;
	struct s_sp	*next;
}						t_sp;

typedef struct			s_pl
{
	t_vector	coord;
	t_vector	orientation;
	t_color		color;
	struct s_pl *next;
}						t_pl;

typedef struct			s_sq
{
	t_vector	center;
	t_vector	orientation;
	float		side;
	t_color		color;
	struct s_sq	*next;
}						t_sq;

typedef struct			s_cy
{
	t_vector	coord;
	t_vector	orientation;
	float		d;
	float		h;
	t_color		color;
	struct s_cy *next;
}						t_cy;

typedef struct			s_cyaux
{
	t_vector	oc;
	t_vector	v_doo;
	t_vector	v_ocoo;
	t_vector	v1;
	t_vector	v2;
	double		d_do;
	double		d_oco;
	double		a;
	double		b;
	double		c;
	double		t1;
	double		t2;
	t_vector	coord_2;
	t_vector	point_1;
	t_vector	point_2;
	t_vector	axis;
	float		d_c1p1a;
	float		d_c2p1a;
	float		d_c1p2a;
	float		d_c2p2a;
}						t_cyaux;

typedef struct			s_tr
{
	t_vector	f_p;
	t_vector	s_p;
	t_vector	t_p;
	t_color		color;
	struct s_tr	*next;
}						t_tr;

typedef struct			s_objs
{
	t_amb		*amb;
	t_light		*light;
	t_sp		*sp;
	t_pl		*pl;
	t_sq		*sq;
	t_cy		*cy;
	t_tr		*tr;
}						t_objs;

typedef struct			s_rt
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			res_x;
	int			res_y;
	t_objs		*o_lst;
	t_cam		*cam_lst;
	t_cam		*current_cam;
}						t_rt;

typedef struct			s_bmp
{
	int			width;
	int			sl;
	int			height;
	int			bpp;
	int			imgsize;
	char		*img;
}						t_bmp;

#endif
