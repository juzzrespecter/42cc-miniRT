/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:32:49 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/26 18:41:09 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"
#include "../inc/minirt.h"

//revisar lal multiplicacion entre matrices y vectores

float length(float *v)
{
	return ((sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2))));
}

void res(float *v1, float *v2, float *vres)
{
	int count;

	count = 0;
	while (count < 3)
		{
			vres[count] = v1[count] - v2[count];
			count++;
		}
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

void normalize(float *v)
{
	int count;
	float mod;

	count = 0;
	mod = length(v);
	while (count < 3)
		{
			v[count] /= mod;
			count++;
		}
}
