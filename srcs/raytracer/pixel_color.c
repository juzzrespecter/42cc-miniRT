/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:40:10 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/01 20:42:23 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool		find_shadows(t_objs *o_lst, t_vector l, t_vector p)
{
	t_ray		ray;
	t_vector	lp;
	float		t;

	lp = v_sub(l, p);
	ray.dir = v_normalize(lp);
	ray.origin = v_add(p, v_scalar(ray.dir, 0.005));
	lp = v_sub(l, ray.origin);
	t = sqrt(v_dot(lp, lp));
	return (lightning_loops(&ray, o_lst, t));
}

static t_color	diff_sum(t_light *l, t_point *p, t_objs *o_lst)
{
	float		dot;
	float		l_const;
	t_color		diff;
	t_vector	l_dir;

	ft_bzero(&diff, sizeof(t_color));
	while (l)
	{
		if (find_shadows(o_lst, l->coord, p->coord) == false)
		{
			l_dir = v_normalize(v_sub(l->coord, p->coord));
			dot = ft_max(0, v_dot(l_dir, p->normal));
			l_const = l->bright * dot * 255;
			diff.r = ft_min((diff.r * 255) + (l->color.r * l_const), 255) / 255;
			diff.g = ft_min((diff.g * 255) + (l->color.g * l_const), 255) / 255;
			diff.b = ft_min((diff.b * 255) + (l->color.b * l_const), 255) / 255;
		}
		l = l->next;
	}
	return (diff);
}

static t_color	amb_sum(t_amb *amb)
{
	t_color amb_color;

	ft_bzero(&amb_color, sizeof(t_color));
	if (amb)
	{
		amb_color.r = amb->color.r * amb->bright;
		amb_color.g = amb->color.g * amb->bright;
		amb_color.b = amb->color.b * amb->bright;
	}
	return (amb_color);
}

unsigned int	pixel_color(t_objs *o_lst, t_point *p)
{
	t_color			amb;
	t_color			diff;
	t_color			obj;
	unsigned int	color;

	if (p->t == -1)
		return (0);
	color = 0;
	amb = amb_sum(o_lst->amb);
	diff = diff_sum(o_lst->light, p, o_lst);
	obj = p->color;
	obj.r *= ft_min(255, ((amb.r * 255) + (diff.r * 255))) / 255;
	obj.g *= ft_min(255, ((amb.g * 255) + (diff.g * 255))) / 255;
	obj.b *= ft_min(255, ((amb.b * 255) + (diff.b * 255))) / 255;
	color = ((((int)(obj.b * 255) | ((int)(obj.g * 255) << 8)) |\
				((int)(obj.r * 255) << 16)) & 0xffffff);
	return (color);
}
