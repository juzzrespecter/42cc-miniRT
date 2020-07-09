/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:49:37 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/09 19:59:54 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

char *draw_image(t_objlst *obj_lst, t_data data)
{
	char *img;
	int bits_per_pixel;
	int size_line;
	int endian;

	//
	img = mlx_get_data_addr(data.img_ptr, &bits_per_pixel, &size_line, &endian);
}
