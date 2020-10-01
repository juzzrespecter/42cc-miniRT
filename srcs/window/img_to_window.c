/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:21:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/01 21:10:36 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	img_to_window(t_rt *index)
{
	void *win_ptr;

	win_ptr = mlx_new_window(index->mlx_ptr, \
			index->res_x, index->res_y, "miniRayTracer scene");
	if (!win_ptr)
		exit_failure(index, "Error: mlx couldn't create window.");
	window_generate_images(index);
	index->win_ptr = win_ptr;
	mlx_key_hook(win_ptr, &window_key_options, index);
	mlx_hook(win_ptr, 17, 1L << 17, &exit_success, index);
	mlx_put_image_to_window(index->mlx_ptr, win_ptr, \
			index->current_cam->img_ptr, 0, 0);
	mlx_loop(index->mlx_ptr);
}
