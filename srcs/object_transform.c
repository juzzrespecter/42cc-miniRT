/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:43:40 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/17 18:08:39 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void rot_x_matrix(float *ov_obj, float *ov_world, float rx_m[4][4])
{
	float theta;
	int i;
	int j;

	theta = dot(ov_obj, ov_world) / (length(ov_obj) * length(ov_world));
	i = 0;
	j = 0;
	while (i < 4)
		{
			while (j < 4)
				{
					rx_m[i][j] = 0;
					j++;
				}
			i++;
			j = 0;
		}
	rx_m[0][0] = 1;
	rx_m[1][1] = cos(theta);
	rx_m[2][1] = sin(theta);
	rx_m[1][2] = -sin(theta);
	rx_m[2][2] = cos(theta);
}

static void rot_y_matrix(float *ov_obj, float *ov_world, float ry_m[4][4])
{
	float theta;
	int i;
	int j;

	theta = dot(ov_obj, ov_world) / (length(ov_obj) * length(ov_world));
	i = 0;
	j = 0;
	while (i < 4)
		{
			while (j < 4)
				{
					ry_m[i][j] = 0;
					j++;
				}
			i++;
			j = 0;
		}
	ry_m[0][0] = cos(theta);
	ry_m[0][2] = sin(theta);
	ry_m[1][1] = 1;
	ry_m[2][0] = -sin(theta);
	ry_m[2][2] = cos(theta);
}

static void rot_z_matrix(float *ov_obj, float *ov_world, float rz_m[4][4])
{
	float theta;
	int i;
	int j;

	theta = dot(ov_obj, ov_world) / (length(ov_obj) * length(ov_world));
	i = 0;
	j = 0;
	while (i < 4)
		{
			while (j < 4)
				{
					rz_m[i][j] = 0;
					j++;
				}
			i++;
			j = 0;
		}
	rz_m[0][0] = cos(theta);
	rz_m[0][1] = -sin(theta);
	rz_m[1][0] = sin(theta);
	rz_m[1][1] = cos(theta);
	rz_m[2][2] = 1;
}

void otow_transform(float ov_obj[3], float ov_world[3], float otow_m[4][4])
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
	matrix_prod(r_m, t_m, otow_m);
}
