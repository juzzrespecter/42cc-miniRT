/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_olst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:27:06 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 19:27:09 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void setup_olst(t_olst *olst)
{
	olst->res = NULL;
	olst->amb = NULL;
	olst->cam = NULL;
	olst->light = NULL;
	olst->sp = NULL;
	olst->pl = NULL;
	olst->sq = NULL;
	olst->cy = NULL;
	olst->tr = NULL;
}
