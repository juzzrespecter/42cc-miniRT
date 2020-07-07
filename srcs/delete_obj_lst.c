/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_obj_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:58:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/07 20:11:20 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	delete_obj_lst(t_objlst *obj_lst)
{
	if (obj_lst->res)
		free(obj_lst->res);
	if (obj_lst->amb)
		free(obj_lst->amb);
}
