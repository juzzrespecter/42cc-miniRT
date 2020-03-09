/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:03:55 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/04 14:00:59 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*******************************************************/
/*																										 */
/*																										 */
/*							esto está mal lol                      */
/*																										 */
/*																										 */
/*******************************************************/



/*static bool square_hit(t_3dvec *ray, float d, t_sq *sq)
{
	float p[2];
	float x_lim[2];
	float y_lim[2];

	p[0] = ray->orig[0] + (d * ray->dir[0]);
	p[1] = ray->orig[1] + (d * ray->dir[1]);
	x_lim[0] = sq->coord[0] - sq->size / 2;
	x_lim[1] = sq->coord[0] + sq->size / 2;
	y_lim[0] = sq->coord[1] - sq->size / 2;
	y_lim[1] = sq->coord[1] + sq->size / 2;
	return (!(p[0] > x_lim[0] && p[0] < x_lim[1] && p[1] > y_lim[0] && p[1] < y_lim[1]) false ? true);
	return ()
	}*/

t_point *sq_c(t_sq *sq, t_3dvec *ray)
{
	t_point *point;
	float oc_vec[3];
	float d;
	int i;

	if (!(point = malloc(sizeof(t_point))))
		return (NULL);
	point->p_coord = NULL;
	point->color = 0;
	point->next = NULL;
	denom = dot(ray->dir, sq->v_norm);
	if (denom < ROUND_ERR)
		return (point);
	i = 0;
	while (i < 3)
		{
			oc_vec[i] = sq->coord[i] - ray->orig[i];
			i++;
		}
	d = dot(oc_vec, pl->v_norm) / denom;
	if (!(square_hit(ray, d, sq)))
		return (point);
	if (!(point->p_coord = malloc(sizeof(float) * 3)))
		return (NULL);
	i = 0;
	while (i < 3)
		{
			point->p_coord[i] = ray->orig[i] + (d * ray->dir[i]);
			i++;
		}
	point->color = rgb_conv(pl->color);
	return (point);
}
