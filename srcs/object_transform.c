/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:43:40 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/16 19:48:27 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void rot_x_matrix(float *ov_obj, float *ov_world, float rx_m[4][4])
{
	float theta;

	theta = dot(ov_obj, ov_world) / (length(ov_obj) * length(ov_world));

}

static void rot_y_matrix(float *ov_obj, float *ov_world, float ry_m[4][4])
{
	float theta;

	theta = dot(ov_obj, ov_world) / (length(ov_obj) * length(ov_world));
}

static void rot_z_matrix(float *ov_obj, float *ov_world, float rz_m[4][4])
{
	float theta;

	theta = dot(ov_obj, ov_world) / (length(ov_obj) * length(ov_world));
}

void otow_transform(float ov_obj[3], float ov_world[3], float otow_m[4][4])
{
	float rx_m[4][4];
	float ry_m[4][4];
	float rz_m[4][4];
	float r_m[4][4];
	float t_m[4][4];

	//construir rx_m
	//construir ry_m
	//construir rz_m
	//construir t
	//multiplicar x * y
	matrix_prod(rx_m, ry_m, ry_m);
	//multiplicar (x * y) * z
	matrix_prod(ry_m, rz_m, r_m);
	//multiplicar r * t
	matrix_prod(r_m, t_m, otow_m);
}
