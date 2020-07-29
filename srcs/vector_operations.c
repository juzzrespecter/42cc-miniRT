/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:32:49 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/29 17:47:23 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"
#include "../inc/minirt.h"

//revisar lal multiplicacion entre matrices y vectores

float length(float *v)
{
	return ((sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2))));
}

float dot(float *v1, float *v2)
{
	return ((v1[0] * v2[0]) + (v1[1] * v2[1]) + (v1[2] * v2[2]));
}

void cross(float *v1, float *v2, float *cross)
{
	cross[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
	cross[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
	cross[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
	cross[3] = 1;
}

void norm(float *v)
{
	int i;
	float mod;

	i = 0;
	mod = length(v);
	while (i < 3)
		{
			v[i] /= mod;
			i++;
		}
}
