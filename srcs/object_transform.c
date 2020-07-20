/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:43:40 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/20 20:06:27 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

static void rot_x_matrix(float *ov_obj, float *ov_world, float rx_m[4][4])
{
	float theta;
	float theta_den;
	float yz_obj[3];
	float yz_world[3];
	int i;

	i = 0;
	while (i < 3)
		{
			yz_obj[i] = ov_obj[i];
			yz_world[i] = ov_world[i];
			i++;
		}
	yz_obj[0] = yz_world[0] = 0;
	if (!(theta_den = length(yz_obj) * length(yz_world)))
		theta = 0;
	else
		theta = acos(dot(yz_obj, yz_world) / theta_den);
	set_id_matrix(rx_m);
	rx_m[0][0] = 1;
	rx_m[1][1] = cos(theta);
	rx_m[2][1] = sin(theta);
	rx_m[1][2] = -sin(theta);
	rx_m[2][2] = cos(theta);
	rx_m[3][3] = 1;
}

static void rot_y_matrix(float *ov_obj, float *ov_world, float ry_m[4][4])
{
	float theta;
	float theta_den;
	float xz_obj[3];
	float xz_world[3];
	int i;

	i = 0;
	while (i < 3)
		{
			xz_obj[i] = ov_obj[i];
			xz_world[i] = ov_world[i];
			i++;
		}
	xz_obj[0] = xz_world[0] = 0;
	if (!(theta_den = length(xz_obj) * length(xz_world)))
		theta = 0;
	else
		theta = acos(dot(xz_obj, xz_world) / theta_den);
	set_id_matrix(ry_m);
	ry_m[0][0] = cos(theta);
	ry_m[0][2] = sin(theta);
	ry_m[1][1] = 1;
	ry_m[2][0] = -sin(theta);
	ry_m[2][2] = cos(theta);
	ry_m[3][3] = 1;
}

static void rot_z_matrix(float *ov_obj, float *ov_world, float rz_m[4][4])
{
	float theta;
	float theta_den;
	float xy_obj[3];
	float xy_world[3];
	int i;

	i = 0;
	while (i < 3)
		{
			xy_obj[i] = ov_obj[i];
			xy_world[i] = ov_world[i];
			i++;
		}
	xy_obj[0] = xy_world[0] = 0;
	if (!(theta_den = length(xy_obj) * length(xy_world)))
		theta = 0;
	else
		theta = acos(dot(xy_obj, xy_world) / theta_den);
	set_id_matrix(rz_m);
	rz_m[0][0] = cos(theta);
	rz_m[0][1] = -sin(theta);
	rz_m[1][0] = sin(theta);
	rz_m[1][1] = cos(theta);
	rz_m[2][2] = 1;
	rz_m[3][3] = 1;
}

static void t_matrix(float *c_world, float t_m[4][4])
{
	int i;
	int j;

	i = 0;
	j = 0;
	set_id_matrix(t_m);
	while (j < 3)
		{
			t_m[j][3] = c_world[j];
			j++;
		}
}

void otow_transform(float *ov_obj, float *ov_world, float *c_world, float otow_m[4][4])
{
	float rx_m[4][4];
	float ry_m[4][4];
	float rz_m[4][4];
	float r_m[4][4];
	float t_m[4][4];

	rot_x_matrix(ov_obj, ov_world, rx_m);
	rot_y_matrix(ov_obj, ov_world, ry_m);
	rot_z_matrix(ov_obj, ov_world, rz_m);
	matrix_prod(rx_m, ry_m, ry_m);
	matrix_prod(ry_m, rz_m, r_m);
	t_matrix(c_world, t_m);
	matrix_prod(t_m, r_m, otow_m);
}
