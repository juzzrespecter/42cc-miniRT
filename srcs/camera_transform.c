/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:54:54 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/20 20:12:31 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void linear_transform(float *normal, float r[4][4])
{
	float temp_up[3];
	float right[4];
	float up[4];

	set_id_matrix(r);
	temp_up[0] = 0;
	temp_up[1] = 1;
	temp_up[0] = 0;
	cross(normal, temp_up, right);
	cross(normal, right, up);
	r[0][0] = normal[0];
	r[0][1] = normal[1];
	r[0][2] = normal[2];
	r[1][0] = right[0];
	r[1][1] = right[1];
	r[1][2] = right[2];
	r[2][0] = up[0];
	r[2][1] = up[1];
	r[2][2] = up[2];
}

static void translation_transform(float *eye, float t[4][4])
{
	set_id_matrix(t);
	t[0][3] = -eye[0];
	t[1][3] = -eye[1];
	t[2][3] = -eye[2];
	t[3][3] = -eye[3];
}

void wtov_transform(float *normal, float *eye, float view_m[4][4])
{
	float r[4][4];
	float t[4][4];

	linear_transform(normal, r);
	translation_transform(eye, t);
	//invertir las dos matrices;
	matrix_prod(r, t, view_m);
}

void ctow_transform(float *normal, float *eye, float ctow_m[4][4])
{
	float r[4][4];
	float t[4][4];

	linear_transform(normal, r);
	translation_transform(eye, t);
	matrix_prod(r, t, ctow_m);
}
