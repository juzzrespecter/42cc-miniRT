/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj2world_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 19:47:25 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/25 19:51:56 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

static void quat2matrix(float *quat, float m[4][4])
{
	set_id_matrix(m);
	m[0][0] = 1 - 2 * (pow(quat[2], 2) + pow(quat[3], 2));
	m[0][1] = 2 * (quat[1] * quat[2] + quat[3] * quat[0]);
	m[0][2] = 2 * (quat[1] * quat[3] + quat[2] * quat[0]);
	m[1][0] = 2 * (quat[1] * quat[2] - quat[3] * quat[0]);
	m[1][1] = 1 - 2 * (pow(quat[1], 2) + pow(quat[3], 2));
	m[1][2] = 2 * (quat[2] * quat[3] + quat[1] * quat[0]);
	m[2][0] = 2 * (quat[1] * quat[3] + quat[2] * quat[0]);
	m[2][1] = 2 * (quat[2] * quat[3] + quat[1] * quat[0]);
	m[2][2] = 1 - 2 * (pow(quat[1], 2) + pow(quat[2], 2));
}

void obj2world_matrix(float *obj_or, float *world_or, float o2w_m[4][4])
{
	float quaternion[4];
	float rot_axis[4];
	float rot_angle;

	normalize(world_or);
	cross(obj_or, world_or, rot_axis);
	normalize(rot_axis);
	rot_angle = acos(dot(obj_or, world_or)) / 2;
	quaternion[0] = cos(rot_angle);
	quaternion[1] = sin(rot_angle) * rot_axis[0];
	quaternion[2] = sin(rot_angle) * rot_axis[1];
	quaternion[3] = sin(rot_angle) * rot_axis[2];
	quat2matrix(quaternion, o2w_m);
}
