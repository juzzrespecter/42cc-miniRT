/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:21:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/15 18:23:11 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void img_to_window(t_rtindex *index)
{
	void *win_ptr;

	win_ptr = mlx_new_window(index->mlx_ptr, index->res_x, index->res_y, "miniRayTracer scene");
	index->win_ptr = win_ptr;
	mlx_key_hook(win_ptr, &window_key_options, index);
	mlx_mouse_hook(win_ptr, &window_click_exit, index);
	mlx_put_image_to_window(index->mlx_ptr, win_ptr, index->current_cam->img_ptr, 0, 0);
	mlx_loop(index->mlx_ptr);	
}
