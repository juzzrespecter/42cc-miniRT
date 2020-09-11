/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:34:34 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/11 19:01:44 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector rot_x(t_vector v, float d)
{
	t_vector v_rot;

	v_rot.x = v.x;
	v_rot.y = v.y * cos(d) - v.z * sin(d);
	v_rot.z = v.y * sin(d) + v.z * cos(d);
	return (v_rot);
}

t_vector rot_y(t_vector v, float d)
{
	t_vector v_rot;

	v_rot.x = v.x * cos(d) + v.z * sin(d);
	v_rot.y = v.y;
	v_rot.z = -v.y * sin(d) + v.z * cos(d);
}

t_vector rot_z(t_vector v, float d)
{
	t_vector v_rot;

	v_rot.x = v.x * cos(d) - v.y * sin(d);
	v_rot.y = v.x * sin(d) + v.y * cos(d);
	v_rot.z = v.z;
}
