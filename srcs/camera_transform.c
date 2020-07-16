/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:54:54 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/16 19:34:13 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void linear_transform(float normal[3], float r[4][4])
{
	float temp_up[3];
	float right[4];
	float up[4];

	temp_up[0] = 0;
	temp_up[1] = 1;
	temp_up[0] = 0;
	cross(normal, temp_up, right);
	cross(normal, right, up);
	r[0][0] = normal[0];
	r[0][1] = normal[1];
	r[0][2] = normal[2];
	r[0][3] = 0;
	r[1][0] = right[0];
	r[1][1] = right[1];
	r[1][2] = right[2];
	r[1][3] = 0;
	r[2][0] = up[0];
	r[2][1] = up[1];
	r[2][2] = up[2];
	r[2][3] = 0;
	r[3][0] = 0;
	r[3][1] = 0;
	r[3][2] = 0;
	r[3][3] = 1;
}

static void translation_transform(float eye[3], float t[4][4])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
		{
			while (j < 3)
				{
					t[i][j] = 0;
					j++;
				}
			i++;
			j = 0;
		}
	t[0][3] = -eye[0];
	t[1][3] = -eye[1];
	t[2][3] = -eye[2];
	t[3][3] = -eye[3];
}

void view_transform(float normal[3], float eye[3], float view_m[4][4])
{
	float r[4][4];
	float t[4][4];

	linear_transform(normal, r);
	translation_transform(eye, t);
	matrix_prod(r, t, view_m);
}

void cam_to_world_transform(float ctow_m[4][4], t_cam *cam)
{

}
