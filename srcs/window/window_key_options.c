/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_key_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:25:15 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/15 17:32:11 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int window_press_esc(t_rtindex *index)
{
	ft_printf("...\n");
	mlx_destroy_window(index->mlx_ptr, index->win_ptr);
	//funcion que borre todas las imagenes de la lista de camaras (index->cam_lst)
	//funcion que borre la lista de camaras (index->cam_lst)
	//funcion que elimine la lista de objetos (index->o_lst)
	exit(EXIT_SUCCESS);
}

int window_key_options(int key, t_rtindex *index)
{
	if (key == ESC_KEY)
		window_press_esc(index);
	if (key == PREV_CAM || key == NEXT_CAM)
		window_change_cam(key, index);
	return (1);
}
