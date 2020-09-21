/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_key_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:25:15 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/21 16:08:01 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int window_press_esc(t_rtindex *index)
{
	t_cam *aux;

	ft_printf("...\n");
	mlx_destroy_window(index->mlx_ptr, index->win_ptr);
	while (index->cam_lst)
	{
		aux = index->cam_lst;
		mlx_destroy_image(index->mlx_ptr, aux->img_ptr);
		index->cam_lst = index->cam_lst->next;
		free(aux);
	}
	delete_olst(index->o_lst);
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
