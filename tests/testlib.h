/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:45:36 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/25 18:16:19 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTLIB_H
# define TESTLIB_H
# include <mlx.h>

typedef struct light
{
	float pos[3];
	float l_int;
	int color[3];
} light;

typedef struct amb
{
	float bright;
	int color[3];
} amb;

typedef struct cam
{
	float vector[3];
	float pos[3];
	float fov;
} cam;

typedef struct sp
{
	float pos[3];
	float radio;
	unsigned char color[3];
} sp;

typedef struct vector
{
	float orig[3];
	float dir[3];
} vector;

typedef struct data
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	int res_x;
	int res_y;
	cam	cam;
} data;

void test(data *data);

#endif
