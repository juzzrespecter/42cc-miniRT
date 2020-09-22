/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:44:07 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/22 20:04:48 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector		vmprod(t_vector v, t_matrix matrix)
{
	t_vector	vprod;

	vprod.x = v_dot(matrix.a, v);
	vprod.y = v_dot(matrix.b, v);
	vprod.z = v_dot(matrix.c, v);
	return (vprod);
}

static t_matrix	fwd_and_up_are_parallel(float y)
{
	t_matrix c2w;

	c2w.a.x = 1;
	c2w.a.y = 0;
	c2w.a.z = 0;
	c2w.b.x = 0;
	c2w.b.y = 0;
	c2w.b.z = y;
	c2w.c.x = 0;
	c2w.c.y = y * -1;
	c2w.c.z = 0;
	return (c2w);
}

t_matrix		matrix_cam2world(t_vector forward)
{
	t_vector	tmp;
	t_vector	up;
	t_vector	right;
	t_matrix	c2w;

	tmp.x = 0;
	tmp.y = 1;
	tmp.z = 0;
	forward = v_normalize(v_scalar(forward, -1));
	right = v_cross(tmp, forward);
	if (!(v_dot(right, right)))
		return (fwd_and_up_are_parallel(forward.y));
	right = v_normalize(right);
	up = v_normalize(v_cross(forward, right));
	c2w.a.x = right.x;
	c2w.a.y = up.x;
	c2w.a.z = forward.x;
	c2w.b.x = right.y;
	c2w.b.y = up.y;
	c2w.b.z = forward.y;
	c2w.c.x = right.z;
	c2w.c.y = up.z;
	c2w.c.z = forward.z;
	return (c2w);
}
