/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_press_esc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 20:15:00 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/14 20:19:03 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int window_press_esc(int key, t_rtindex *index)
{
	if (key == ESC_KEY)
	{
		ft_printf("...");
		mlx_destroy_window(index->data->mlx_ptr, index->data->win_ptr);
		//funcion que borre todas las imagenes de la lista de camaras (index->cam_lst)
		//funcion que borre la lista de camaras (index->cam_lst)
		//funcion que elimine la lista de objetos (index->o_lst)
		exit(EXIT_SUCCESS);
	}
	return (1);
}
