/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:10:10 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/29 20:25:03 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void init_lst(t_lst *obj_lst)
{
	obj_lst->r = NULL;
	obj_lst->a = NULL;
	obj_lst->c_lst = NULL;
	obj_lst->sp_lst = NULL;
	obj_lst->sq_lst = NULL;
	obj_lst->pl_lst = NULL;
	obj_lst->cy_lst = NULL;
	obj_lst->tr_lst = NULL;
}

void destroy_lst(t_lst *obj_lst)
{
	int i;

	if (obj_lst->r)
		{
			free(obj_lst->r);
			obj_lst->r = NULL;
		}
}
