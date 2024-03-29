/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_generate_images.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 20:22:54 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/03 17:09:51 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	window_generate_images(t_rt *index)
{
	t_cam *cam;

	cam = index->cam_lst->next;
	while (cam)
	{
		if (!(cam->img = ray_tracer(index, cam)))
			exit_failure(index, "Failed to create the scene.");
		cam = cam->next;
	}
}
