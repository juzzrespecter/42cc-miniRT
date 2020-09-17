/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_change_cam.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:44:12 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/17 18:15:24 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int get_cam_pos(t_cam *alst, t_cam *current_cam)
{
	int pos;

	pos	= 1;
	while (!(alst == current_cam))
	{
		alst = alst->next;
		pos++;
	}
	return (pos);
}

static int get_number_of_cams(t_cam *cam_lst)
{
	int n;

	n = 0;
	while (cam_lst)
	{
		cam_lst = cam_lst->next;
		n++;
	}
	return (n);
}

static t_cam *get_last_cam(t_cam *cam)
{
	while (cam->next)
		cam = cam->next;
	return (cam);
}

static t_cam *get_prev_cam(t_cam *cam, int pos)
{
	int count;

	count = 1;
	while (count < pos - 1)
	{
		count++;
		cam = cam->next;
	}
	return (cam);
}

int window_change_cam(int key, t_rtindex *index)
{
	int cam_pos;
	int n_cams;

	cam_pos = get_cam_pos(index->cam_lst, index->current_cam);
	n_cams = get_number_of_cams(index->cam_lst);
	if (n_cams == 1)
		return (1);
	if (key == NEXT_CAM)
		{
			if (cam_pos == n_cams)
				index->current_cam = index->cam_lst;
			else
				index->current_cam = index->current_cam->next;
		}
	if (key == PREV_CAM)
	{
		if (cam_pos == 1)
			index->current_cam = get_last_cam(index->cam_lst);
		else
			index->current_cam = get_prev_cam(index->cam_lst, cam_pos);
	}
	mlx_put_image_to_window(index->mlx_ptr, index->win_ptr, index->current_cam->img_ptr, 0, 0);
	return (1);
}
