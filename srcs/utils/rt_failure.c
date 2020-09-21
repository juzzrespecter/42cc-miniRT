/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_failure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:03:03 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/21 16:57:06 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void rt_failure(t_rtindex *index, char *err_msg)
{
	t_cam *aux;

	ft_printf("%s\n", err_msg);
	if (index)
	{
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
