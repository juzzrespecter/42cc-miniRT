/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_loops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:32:52 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/14 20:37:18 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_point *sp_loop(t_sp *sp, t_point *point, t_cam *cam, t_3dvec ray)
{
	t_point *a_point;
	t_point *p_aux;
	t_sp *sp_aux;

	a_point = point;
	p_aux = point;
	sp_aux = sp;
	while (p_aux)
		p_aux = p_aux->next;
	while (sp_aux)
		{
			p_aux = sp_collision(sp_aux, cam, ray);
			sp_aux = sp_aux->next;
		}
}
