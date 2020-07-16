/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:07:20 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/16 17:25:34 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//view matrix para transformar el vector oc y el rayo en las coordenadas
//de la camara

void sp_collision(t_sp *sp, t_point *point, t_cam *cam, t_3dvec ray)
{
	float oc_vec[4];
	float oc_view[4];
	float view_m[4][4];
	int i;

	i = 0;
	while (i < 3)
		{
			oc_vec[i] = sp->coord[i] - cam->coord[i];
			i++;
		}
	view_transform(cam->vector, cam->coord, view_m);
	m_v_prod(oc_vec, view_m, oc_view);
	//test matrices: ray.orig deberia ser nulo
}