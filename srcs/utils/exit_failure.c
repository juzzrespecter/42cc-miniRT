/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_failure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:00:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/30 19:00:39 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void exit_failure(t_rtindex *index, char *err_msg)
{
	t_cam *aux;

	ft_printf("%s\n", err_msg);
	if (index)
	{
		if (index->o_lst)
			delete_olst(index->o_lst);
		aux = index->cam_lst;
		while (index->cam_lst)
		{
			aux = index->cam_lst->next;
			free(index->cam_lst);
			index->cam_lst = aux;
		}
		free(index);
	}
	exit(EXIT_FAILURE);
}
