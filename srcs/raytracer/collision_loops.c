/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_loops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:47 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/29 18:06:58 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_point	*collision_loops_5(t_objs *o_lst, t_ray *ray, t_point *point)
{
	t_tr	*aux;
	double	t;

	aux = o_lst->tr;
	while (aux)
	{
		t = collision_triangle(aux, ray);
		if (t > ERROR && (point->t > t || point->t == -1))
		{
			point->t = t;
			point->coord = v_add(ray->origin, v_scalar(ray->dir, t));
			point->normal = normal_triangle(aux->f_p, aux->s_p, aux->t_p);
			if (v_dot(point->normal, ray->dir) > 0)
				point->normal = v_scalar(point->normal, -1);
			point->color = aux->color;
		}
		aux = aux->next;
	}
	return (point);
}

static t_point	*collision_loops_4(t_objs *o_lst, t_ray *ray, t_point *point)
{
	t_cy	*aux;
	double	t;

	aux = o_lst->cy;
	while (aux)
	{
		t = collision_cylinder(aux, ray);
		if (t > ERROR && (point->t > t || point->t == -1))
		{
			point->t = t;
			point->coord = v_add(ray->origin, v_scalar(ray->dir, t));
			point->normal = normal_cylinder(aux, point->coord);
			if (v_dot(point->normal, ray->dir) > 0)
				point->normal = v_scalar(point->normal, -1);
			point->color = aux->color;
		}
		aux = aux->next;
	}
	point = collision_loops_5(o_lst, ray, point);
	return (point);
}

static t_point	*collision_loops_3(t_objs *o_lst, t_ray *ray, t_point *point)
{
	t_sq	*aux;
	double	t;

	aux = o_lst->sq;
	while (aux)
	{
		t = collision_square(aux, ray);
		if (t > ERROR && (point->t > t || point->t == -1))
		{
			point->t = t;
			point->coord = v_add(ray->origin, v_scalar(ray->dir, t));
			point->normal = aux->orientation;
			if (v_dot(point->normal, ray->dir) > 0)
				point->normal = v_scalar(point->normal, -1);
			point->color = aux->color;
		}
		aux = aux->next;
	}
	point = collision_loops_4(o_lst, ray, point);
	return (point);
}

static t_point	*collision_loops_2(t_objs *o_lst, t_ray *ray, t_point *point)
{
	t_pl	*aux;
	double	t;

	aux = o_lst->pl;
	while (aux)
	{
		t = collision_plane(aux->orientation, aux->coord, ray);
		if (t > ERROR && (point->t > t || point->t == -1))
		{
			point->t = t;
			point->coord = v_add(ray->origin, v_scalar(ray->dir, t));
			point->normal = aux->orientation;
			if (v_dot(point->normal, ray->dir) > 0)
				point->normal = v_scalar(point->normal, -1);
			point->color = aux->color;
		}
		aux = aux->next;
	}
	point = collision_loops_3(o_lst, ray, point);
	return (point);
}

t_point			*collision_loops(t_objs *o_lst, t_ray *ray)
{
	t_sp	*aux;
	double	t;
	t_point	*point;

	if (!(point = calloc(sizeof(t_point), 1)))
		return (NULL);
	aux = o_lst->sp;
	point->t = -1;
	while (aux)
	{
		t = collision_sphere(aux, ray);
		if (t > ERROR && (point->t > t || point->t == -1))
		{
			point->t = t;
			point->coord = v_add(ray->origin, v_scalar(ray->dir, t));
			point->normal = v_normalize(v_sub(point->coord, aux->center));
			point->color = aux->color;
		}
		aux = aux->next;
	}
	point = collision_loops_2(o_lst, ray, point);
	return (point);
}
