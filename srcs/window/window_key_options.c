/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_key_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:25:15 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/30 17:16:17 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int window_key_options(int key, t_rtindex *index)
{
	if (key == ESC_KEY)
		exit_success(index);
	if (key == PREV_CAM || key == NEXT_CAM)
		window_change_cam(key, index);
	return (1);
}
