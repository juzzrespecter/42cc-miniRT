/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_obj_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:04:51 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/08 17:07:20 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void setup_obj_lst(t_objlst *obj_lst)
{
	printf("\t\tin setup. (%p)\n", obj_lst->cam);
	obj_lst->res = NULL;
	obj_lst->amb = NULL;
	obj_lst->cam = NULL;
	obj_lst->sp = NULL;
	obj_lst->pl = NULL;
	obj_lst->sq = NULL;
	obj_lst->cy = NULL;
	obj_lst->tr = NULL;
	printf("\t\tout setup. (%p)\n", obj_lst->cam);
}
