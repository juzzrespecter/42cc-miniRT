/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:44:07 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 19:47:19 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector vmprod(t_vector v, t_vector matrix[3])
{
	t_vector vprod;

	vprod.x = v_dot(v, matrix[0]);
	vprod.y = v_dot(v, matrix[1]);
	vprod.z = v_dot(v, matrix[2]);
	return (vprod);
}
