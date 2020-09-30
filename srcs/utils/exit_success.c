/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_success.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:59:44 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/30 19:46:37 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_success(t_rtindex *index)
{
	t_cam	*aux;

	if (index->win_ptr)
		mlx_destroy_window(index->mlx_ptr, index->win_ptr);
	while (index->cam_lst)
	{
		aux = index->cam_lst;
		if (aux->img_ptr)
			mlx_destroy_image(index->mlx_ptr, aux->img_ptr);
		index->cam_lst = index->cam_lst->next;
		free(aux);
	}
	delete_olst(index->o_lst);
	free(index);
	ft_printf("Exited successfully.\n");
	exit(EXIT_SUCCESS);
	return (1);
}
