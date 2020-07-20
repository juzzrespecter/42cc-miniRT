/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:44:07 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/20 19:57:18 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void matrix_prod(float m1[4][4], float m2[4][4], float m_res[4][4])
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
