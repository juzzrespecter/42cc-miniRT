/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:09:12 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/01 19:22:28 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

t_vector	v_add(t_vector v1, t_vector v2)
{
	t_vector v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vector	v_sub(t_vector v1, t_vector v2)
{
	t_vector v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_vector	v_scalar(t_vector v, float n)
{
	v.x *= n;
	v.y *= n;
	v.z *= n;
	return (v);
}

float		v_mod(t_vector v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

t_vector	v_normalize(t_vector v)
{
	float mod;

	mod = v_mod(v);
	v.x /= mod;
	v.y /= mod;
	v.z /= mod;
	return (v);
}
