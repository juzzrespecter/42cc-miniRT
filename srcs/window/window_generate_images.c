/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_generate_images.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 20:22:54 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/14 20:28:57 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void window_generate_images(t_rtindex *index)
{
	t_cam *cam;
	t_data *data;

	cam = index->cam_lst;
	data = index->data;
	cam = cam->next;
	while (cam)
	{
		if (!(cam->img = ray_tracer(index->o_lst, cam, data)))
		   rt_failure(index, "error bla bla");
		cam = cam->next;	
	}
}
