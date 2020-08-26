/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_save_bmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:34:19 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/25 19:54:01 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt"

void *image_save_bmp(char *img_ptr)
{
	int fd;
	char *bmp_header;

	fd = open("scene.bmp", O_CREAT | O_WRONLY);

}
