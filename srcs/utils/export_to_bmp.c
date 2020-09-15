/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_to_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:11:04 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/15 17:09:27 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

const int FILE_HEADER_SIZE = 14;
const int INFO_HEADER_SIZE = 40;

static unsigned char *create_file_header(unsigned int img_size)
{
	int file_size;
	unsigned char *file_header;

	if (!(file_header = (unsigned char *)ft_calloc(FILE_HEADER_SIZE, sizeof(unsigned char))))
		return (NULL);
	file_size = INFO_HEADER_SIZE + FILE_HEADER_SIZE + img_size;
	*file_header = (unsigned char)0x42;
	*(file_header + 1) = (unsigned char)0x4D;
	*(file_header + 2) = (unsigned char)file_size;
	*(file_header + 3) = (unsigned char)(file_size >> 8);
	*(file_header + 4) = (unsigned char)(file_size >> 16);
	*(file_header + 5) = (unsigned char)(file_size >> 24);
	*(file_header + 10) = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	return (file_header);
}

static unsigned char *create_info_header(t_rtindex *index)
{
	unsigned char *info_header;

	if (!(info_header = ft_calloc(INFO_HEADER_SIZE, sizeof(unsigned char))))
		return (NULL);
	*info_header = (unsigned char)INFO_HEADER_SIZE;
	*(info_header + 4) = (unsigned char)index->res_x;
	*(info_header + 5) = (unsigned char)(index->res_x >> 8);
	*(info_header + 6) = (unsigned char)(index->res_x >> 16);
	*(info_header + 7) = (unsigned char)(index->res_x >> 24);
	*(info_header + 8) = (unsigned char)index->res_y;
	*(info_header + 9) = (unsigned char)(index->res_y >> 8);
	*(info_header + 10) = (unsigned char)(index->res_y >> 16);
	*(info_header + 11) = (unsigned char)(index->res_y >> 24);
	*(info_header + 12) = 1;
	*(info_header + 14) = (unsigned char)index->current_cam->bpp;
	return (info_header);
}

void *export_to_bmp(t_rtindex *index)
{
	int fd;
	unsigned int img_size;
	unsigned char *file_header;
	unsigned char *info_header;

	fd = open("scene.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd < 0)
		return (NULL);
	img_size = index->res_x * index->res_y * (index->current_cam->bpp / 8);
	if (!(file_header = create_file_header(img_size)))
		return (NULL);
	if (!(info_header = create_info_header(index)))
		return (NULL);
	write(fd, file_header, FILE_HEADER_SIZE);
	write(fd, info_header, INFO_HEADER_SIZE);
	write(fd, index->current_cam->img, img_size);
	return (index);
}
