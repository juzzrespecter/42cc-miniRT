/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:32:49 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/16 19:43:42 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"
#include "../inc/minirt.h"

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

void m_v_prod(float *v, float matrix[4][4], float *v_prod)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
		{
			while (j < 4)
				{
					v_prod[i] += v[j] * matrix[i][j];
					j++;
				}
			i++;
			j = 0;
		}
}
