/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_failure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:03:03 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/18 19:00:07 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void rt_failure(t_rtindex *index, char *err_msg)
{
	//posibilidad de que aun no se haya montado el index??
	ft_printf("%s\n", err_msg);
	if (!(index == NULL))
	{
		delete_olst(index->o_lst);
	
	//borrar la lista de camaras
	}
	exit(EXIT_FAILURE);
}
