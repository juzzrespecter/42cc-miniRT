/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_obj2world.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:34:48 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/15 18:34:58 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix quat2matrix(float *quat)
{
	t_matrix q2m;

	q2m.a.x = 1 - 2 * (pow(quat[2], 2) + pow(quat[3], 2));
	q2m.a.y = 2 * (quat[1] * quat[2] + quat[3] * quat[0]);
	q2m.a.z = 2 * (quat[1] * quat[3] + quat[2] * quat[0]);
	q2m.b.x = 2 * (quat[1] * quat[2] - quat[3] * quat[0]);
	q2m.b.y = 1 - 2 * (pow(quat[1], 2) + pow(quat[3], 2));
	q2m.b.z = 2 * (quat[2] * quat[3] + quat[1] * quat[0]);
	q2m.c.x = 2 * (quat[1] * quat[3] + quat[2] * quat[0]);
	q2m.c.y = 2 * (quat[2] * quat[3] + quat[1] * quat[0]);
	q2m.c.z = 1 - 2 * (pow(quat[1], 2) + pow(quat[2], 2));
	return (q2m);
}

t_matrix matrix_obj2world(t_vector obj_or, t_vector world_or)
{
	float quaternion[4];
	t_vector rot_axis;
	float rot_angle;
	t_matrix m;

	world_or = v_normalize(world_or);
	rot_axis = v_cross(obj_or, world_or);
	v_normalize(rot_axis);
	rot_angle = acos(v_dot(obj_or, world_or)) / 2;
	quaternion[0] = cos(rot_angle);
	quaternion[1] = sin(rot_angle) * rot_axis.x;
	quaternion[2] = sin(rot_angle) * rot_axis.y;
	quaternion[3] = sin(rot_angle) * rot_axis.z;
	m = quat2matrix(quaternion);
	return (m);
}
