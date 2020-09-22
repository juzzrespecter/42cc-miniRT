/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_vector_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:17:07 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/22 20:05:16 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float v_dot(t_vector v1, t_vector v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_vector v_cross(t_vector v1, t_vector v2)
{
	t_vector v;

	v.x = (v1.y * v2.z) - (v1.z * v2.y);
	v.y = (v1.z * v2.x) - (v1.x * v2.z);
	v.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (v);
}
