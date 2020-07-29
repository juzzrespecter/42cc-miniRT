/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam2world_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:09:20 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/29 16:18:29 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

void cam2world_matrix(float *forward, float *eye, float c2w_m[4][4])
{
	float tmp[4];
	float up[4];
	float right[4];

	tmp[0] = 0;
	tmp[1] = 1;
	tmp[2] = 0;
	tmp[3] = 1;
	cross(forward, tmp, right);
	norm(right);
	cross(forward, right, up);
	norm(up);
	set_id_matrix(c2w_m);
	c2w_m[0][0] = right[0];
	c2w_m[0][1] = right[1];
	c2w_m[0][2] = right[2];
	c2w_m[1][0] = up[0];
	c2w_m[1][1] = up[1];
	c2w_m[1][2] = up[2];
	c2w_m[2][0] = forward[0];
	c2w_m[2][1] = forward[1];
	c2w_m[2][2] = forward[2];
	c2w_m[3][0] = eye[0];
	c2w_m[3][1] = eye[1];
	c2w_m[3][2] = eye[2];
}
