/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:44:01 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/29 18:08:43 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	normal_cylinder(t_cy *cy, t_vector point)
{
	t_vector	normal;
	t_vector	op;
	t_vector	axis;
	t_vector	axis_point;

	op = v_sub(point, cy->coord);
	axis = v_scalar(cy->orientation, v_dot(cy->orientation, op));
	axis_point = v_add(cy->coord, axis);
	normal = v_normalize(v_sub(point, axis_point));
	return (normal);
}

double		cylinder_height(t_cy *cy, t_ray *ray, t_cyaux *aux)
{
	aux->coord_2 = v_add(cy->coord, v_scalar(cy->orientation, cy->h));
	aux->axis = v_sub(aux->coord_2, cy->coord);
	aux->point_1 = v_add(ray->origin, v_scalar(ray->dir, aux->t1));
	aux->d_c1p1a = v_dot(v_sub(aux->point_1, cy->coord), aux->axis);
	aux->d_c2p1a = v_dot(v_sub(aux->point_1, aux->coord_2), aux->axis);
	if (aux->t1 > 0.0 && aux->d_c1p1a > 0.0 && aux->d_c2p1a < 0.0)
		return (aux->t1);
	aux->point_2 = v_add(ray->origin, v_scalar(ray->dir, aux->t2));
	aux->d_c1p2a = v_dot(v_sub(aux->point_2, cy->coord), aux->axis);
	aux->d_c2p2a = v_dot(v_sub(aux->point_2, aux->coord_2), aux->axis);
	if (aux->t2 > 0.0 && aux->d_c1p2a > 0.0 && aux->d_c2p2a < 0.0)
		return (aux->t2);
	return (-1);
}

double		collision_cylinder(t_cy *cy, t_ray *ray)
{
	double	sqrt_ec;
	t_cyaux	aux;

	ft_bzero(&aux, sizeof(t_cyaux));
	aux.oc = v_sub(ray->origin, cy->coord);
	aux.d_do = v_dot(cy->orientation, ray->dir);
	aux.d_oco = v_dot(cy->orientation, aux.oc);
	aux.v_doo = v_scalar(cy->orientation, aux.d_do);
	aux.v_ocoo = v_scalar(cy->orientation, aux.d_oco);
	aux.v1 = v_sub(ray->dir, aux.v_doo);
	aux.v2 = v_sub(aux.oc, aux.v_ocoo);
	aux.a = v_dot(aux.v1, aux.v1);
	aux.b = 2 * v_dot(aux.v1, aux.v2);
	aux.c = v_dot(aux.v2, aux.v2) - pow(cy->d / 2, 2);
	sqrt_ec = (aux.b * aux.b) - (4 * aux.a * aux.c);
	if (sqrt_ec < 0)
		return (-1);
	aux.t1 = ((-1 * aux.b) - sqrt(sqrt_ec)) / (2 * aux.a);
	aux.t2 = ((-1 * aux.b) + sqrt(sqrt_ec)) / (2 * aux.a);
	return (cylinder_height(cy, ray, &aux));
}
