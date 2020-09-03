/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:44:07 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/03 19:00:29 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void m_res_fill(float m[4][4], float m_res[4][4])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
		{
			while (j < 4)
				{
					m_res[i][j] = m[i][j];
					j++;
				}
			i++;
			j = 0;
		}
}

void mprod(float m1[4][4], float m2[4][4], float m_res[4][4])
{
	float m_aux[4][4];
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
		{
			while (j < 4)
				{
					m_aux[i][j] = m1[i][0] * m2[0][j];
					m_aux[i][j] += m1[i][2] * m2[2][j];
					m_aux[i][j] += m1[i][1] * m2[1][j];
					m_aux[i][j] += m1[i][3] * m2[3][j];
					j++;
				}
			i++;
			j = 0;
		}
	m_res_fill(m_aux, m_res);
}

void set_id_matrix(float matrix[4][4])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
		{
			while (j < 4)
				{
					matrix[i][j] = 1 * (i == j);
					j++;
				}
			i++;
			j = 0;
		}
}

void translate(float *point, float *move)
{
	int i;

	i = 0;
	while (i < 3)
		{
			point[i] += move[i];
			i++;
		}
}

void mprint(float matrix[4][4])
{
	int i = 0, j = 0;

	printf("matrix: \n");
	while (i < 4)
	{
		printf("( ");
		while (j < 4)
		{
			if (j != 3)
				printf(" %.2f, ", matrix[i][j]);
			else
				printf(" %.2f ", matrix[i][j]);
			j++;
		}
		printf(")\n");
		j = 0;
		i++;
	}
}

void vmprod(float *v, float matrix[4][4], float *v_prod)
{
	int i;
	int j;

	i = 0;
	j = 0;
	v_prod[0] = 0;
	v_prod[1] = 0;
	v_prod[2] = 0;
	v_prod[3] = 1;
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
