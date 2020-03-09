/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:27:56 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/04 19:09:04 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point *pl_ray_col(t_tr *tr, t_3dvec *ray)
{
	float vec1[3];
	float vec2[3];
	float *vec3;
	t_pl *pl;
	int i;

	i = 0;
	while (i < 3)
		{
			vec1[i] = tr->p2[i] - tr->p1[i];
			vec2[i] = tr->p3[i] - tr->p1[i];
			i++;
		}
	if (!(vec3 = cross(vec1, vec2) && pl = malloc(sizeof(t_pl))))
		return (NULL);
	i = 0;
	while (i < 3)
		{
			pl->coord[i] = p1[i];
			pl->v_norm[i] = vec3[i];
		}
	return (pl_c(pl, ray));
}

t_point *col_in_tr(t_point *point, t_tr *tr)
{
	float edges[3][3];
	float pvecs[3][3];
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < 3)
		{
			while (i < 3)
				{
					edges[j][i] = tr->p2[i] - tr->p1[i];
					pvecs[j][i] = point->p_coord[i] - tr->p1[i];
					i++;
				 }
			if (!cross(tr->v_norm, dot(edges[j], pvecs[j])))
				return (NULL);
			i = 0;
			j++;
		}
	return (point);
}

t_point *tr_c(t_tr *tr, t_3dvec *ray)
{
	t_point *point;
	t_point *err_point;

	if (!(err_point = malloc(sizeof(t_point))))
		return (NULL);
	err_point->p_coord = NULL;
	err_point->color = 0;
	err_point->next = NULL;
	if (!(point = pl_ray_col(tr, ray)))
		return (NULL);
	if (!(point->p_coord))
		return (err_point);
	return (col_in_tr(point, tr) ? point : err_point);
}
