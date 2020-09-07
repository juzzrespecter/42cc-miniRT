/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj2world_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 19:47:25 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 19:50:35 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static void quat2matrix(float *quat, t_vector m[3])
{
	m[0].x = 1 - 2 * (pow(quat[2], 2) + pow(quat[3], 2));
	m[0].y = 2 * (quat[1] * quat[2] + quat[3] * quat[0]);
	m[0].z = 2 * (quat[1] * quat[3] + quat[2] * quat[0]);
	m[1].x = 2 * (quat[1] * quat[2] - quat[3] * quat[0]);
	m[1].y = 1 - 2 * (pow(quat[1], 2) + pow(quat[3], 2));
	m[1].z = 2 * (quat[2] * quat[3] + quat[1] * quat[0]);
	m[2].x = 2 * (quat[1] * quat[3] + quat[2] * quat[0]);
	m[2].y = 2 * (quat[2] * quat[3] + quat[1] * quat[0]);
	m[2].z = 1 - 2 * (pow(quat[1], 2) + pow(quat[2], 2));
}

void obj2world_matrix(t_vector obj_or, t_vector world_or, t_vector o2w_m[3])
{
	float quaternion[4];
	t_vector rot_axis;
	float rot_angle;

	world_or = v_normalize(world_or);
	rot_axis = v_cross(obj_or, world_or);
	v_normalize(rot_axis);
	rot_angle = acos(v_dot(obj_or, world_or)) / 2;
	quaternion[0] = cos(rot_angle);
	quaternion[1] = sin(rot_angle) * rot_axis.x;
	quaternion[2] = sin(rot_angle) * rot_axis.y;
	quaternion[3] = sin(rot_angle) * rot_axis.z;
	quat2matrix(quaternion, o2w_m);
}
