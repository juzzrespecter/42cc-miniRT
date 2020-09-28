/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_click_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 20:19:16 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/28 19:19:48 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int window_click_exit(int button, int x, int y, t_rtindex *index)
{
	(void) index;
	printf("de momento esto no hace nada... (%d, %d, %d).\n", button, x, y);
	return (1);
}
