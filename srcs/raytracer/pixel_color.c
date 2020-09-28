/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:40:10 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/28 21:47:09 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool		find_shadows(t_objects *o_lst, t_vector l, t_vector p)
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

static t_color	diff_color_sum(t_light *l, t_point *p, t_objects *o_lst)
{
	float		dot;
	float		l_const;
	t_color		diff_color;
	t_vector	l_dir;

	ft_bzero(&diff_color, sizeof(t_color));
	while (l)
	{
		if (find_shadows(o_lst, l->coord, p->coord) == false)
		{
			l_dir = v_normalize(v_sub(l->coord, p->coord));
			dot = ft_max(0, v_dot(l_dir, p->normal));
			l_const = l->bright * dot * 255;
			diff_color.r = ft_min((diff_color.r * 255) + (l->color.r * l_const), 255) / 255;
			diff_color.g = ft_min((diff_color.g * 255) + (l->color.g * l_const), 255) / 255;
			diff_color.b = ft_min((diff_color.b * 255) + (l->color.b * l_const), 255) / 255;
		}
		l = l->next;
	}
	return (diff_color);
}

static t_color	amb_color_sum(t_amb *amb)
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

unsigned int	pixel_color(t_objects *o_lst, t_point *p)
{
	t_color			amb_color;
	t_color			diff_color;
	t_color			object_color;
	unsigned int	color;

	if (p->t == -1)
		return (0);
	color = 0;
	amb_color = amb_color_sum(o_lst->amb);
	diff_color = diff_color_sum(o_lst->light, p, o_lst);
	object_color = p->color;
	object_color.r *= ft_min(255, ((amb_color.r * 255) + (diff_color.r * 255))) / 255; 
	object_color.g *= ft_min(255, ((amb_color.g * 255) + (diff_color.g * 255))) / 255; 
	object_color.b *= ft_min(255, ((amb_color.b * 255) + (diff_color.b * 255))) / 255; 
	color = ((((int)(object_color.b * 255) | ((int)(object_color.g * 255) << 8)) |\
			   	((int)(object_color.r * 255) << 16)) & 0xffffff);
	return (color);
}
