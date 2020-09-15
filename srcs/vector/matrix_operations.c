/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:44:07 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/15 18:20:52 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector vmprod(t_vector v, t_matrix matrix)
{
	t_vector vprod;

	vprod.x = v_dot(v, matrix.a);
	vprod.y = v_dot(v, matrix.b);
	vprod.z = v_dot(v, matrix.c);
	return (vprod);
}

t_matrix matrix_cam2world(t_vector forward)
{
	t_vector tmp;
	t_vector up;
	t_vector right;
	t_matrix c2w;

	tmp.x = 0;
	tmp.y = 1;
	tmp.z = 0;
	forward = v_normalize(forward);
	right = v_normalize(v_cross(tmp, forward));
	up = v_normalize(v_cross(forward, right));
	c2w.a = right;
	c2w.b = up;
	c2w.c = forward;
	return (c2w);
}
