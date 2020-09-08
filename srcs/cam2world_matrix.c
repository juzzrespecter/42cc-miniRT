/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam2world_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:09:20 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/08 16:49:01 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

void cam2world_matrix(t_vector forward, t_vector c2w_m[3])
{
	t_vector tmp;
	t_vector up;
	t_vector right;

	tmp.x = 0;
	tmp.y = 1;
	tmp.z = 0;
	forward = v_normalize(v_scalar(forward, -1));
	right = v_normalize(v_cross(forward, tmp));
	up = v_normalize(v_cross(forward, right));
	c2w_m[0] = right;
	c2w_m[1] = up;
	c2w_m[2] = forward;
}
