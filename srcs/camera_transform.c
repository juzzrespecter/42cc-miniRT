/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:54:54 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/21 18:20:48 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void ctow_transform(float *forward, float *eye, float m[4][4])
{
	float temp_up[3];
	float right[4];
	float up[4];

	set_id_matrix(m);
	temp_up[0] = 0;
	temp_up[1] = 1;
	temp_up[0] = 0;
	cross(forward, temp_up, right);
	cross(forward, right, up);
	m[0][0] = forward[0];
	m[0][1] = forward[1];
	m[0][2] = forward[2];
	m[1][0] = right[0];
	m[1][1] = right[1];
	m[1][2] = right[2];
	m[2][0] = up[0];
	m[2][1] = up[1];
	m[2][2] = up[2];
	m[0][3] = eye[0];
	m[1][3] = eye[1];
	m[2][3] = eye[2];
	m[3][3] = eye[3];
}

void wtov_transform(float *forward, float *eye, float view_m[4][4])
{
	//invertir las dos matrices;
}
