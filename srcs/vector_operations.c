/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:32:49 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/14 20:30:24 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"
#include "../inc/minirt.h"

float length(t_3dvec v)
{
	return ((sqrt(pow(v.dir[0], 2) + pow(v.dir[1], 2) + pow(v.dir[2], 2))));
}

float dot(t_3dvec v1, t_3dvec v2)
{
	return ((v1.dir[0] * v2.dir[0]) + (v1.dir[1] * v2.dir[1]) + (v1.dir[2] * v2.dir[2]));
}

t_3dvec cross(t_3dvec v1, t_3dvec v2)
{
	t_3dvec cross;

	cross.dir[0] = (v1.dir[1] * v2.dir[2]) - (v1.dir[2] * v2.dir[1]);
	cross.dir[1] = (v1.dir[2] * v2.dir[0]) - (v1.dir[0] * v2.dir[2]);
	cross.dir[2] = (v1.dir[0] * v2.dir[1]) - (v1.dir[1] * v2.dir[0]);
	return (cross);
}

t_3dvec m_v_prod(t_3dvec v, float matrix[4][4])
{
	t_3dvec v_res;
	int i;
	int j;

	i = 0;
	j = 0;
	v_res.orig[0] = v.orig[0];
	v_res.orig[1] = v.orig[1];
	v_res.orig[2] = v.orig[2];
	v_res.orig[3]	= 1;
	while (i < 4)
		{
			while (j < 4)
				{
					v_res.dir[i] += v.dir[j] * matrix[i][j];
					j++;
				}
			i++;
			j = 0;
		}
	return (v_res);
}

void matrix_prod(float m1[4][4], float m2[4][4], float m_res[4][4])
{
	float m_aux[4][4];
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
		{
			while (j < 4)
				{
					m_aux[i][j] = 0;
					while (k < 4)
						{
							m_aux[i][j] += m1[i][k] * m2[k][i];
							k++;
						}
					j++;
				}
			i++;
			j = 0;
		}
	i = 0;
	j = 0;
	while (i < 4)
		{
			while (j < 4)
				{
					m_res[i][j] = m_aux[i][j];
					j++;
				}
			i++;
			j = 0;
		}
}
