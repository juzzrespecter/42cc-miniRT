/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_to_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:11:04 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/29 22:28:03 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static unsigned char	*create_file_header(unsigned int img_size)
{
	int				file_size;
	unsigned char	*file_header;

	if (!(file_header = malloc(FILE_HEADER_SIZE * sizeof(unsigned char))))
		return (NULL);
	ft_bzero(file_header, FILE_HEADER_SIZE);
	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + img_size;
	*file_header = (unsigned char)0x42;
	*(file_header + 1) = (unsigned char)0x4D;
	*(file_header + 2) = (unsigned char)file_size;
	*(file_header + 3) = (unsigned char)(file_size >> 8);
	*(file_header + 4) = (unsigned char)(file_size >> 16);
	*(file_header + 5) = (unsigned char)(file_size >> 24);
	*(file_header + 10) = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	return (file_header);
}

static unsigned char	*create_info_header(t_rtindex *index)
{
	unsigned char *info_header;
	int				res_x;
	int				res_y;

	res_x = index->res_x;
	res_y = (index->res_y < 0) ? index->res_y : -(index->res_y);
	if (!(info_header = malloc(INFO_HEADER_SIZE * sizeof(unsigned char))))
		return (NULL);
	ft_bzero(info_header, INFO_HEADER_SIZE);
	*info_header = (unsigned char)INFO_HEADER_SIZE;
	*(info_header + 4) = (unsigned char)(res_x);
	*(info_header + 5) = (unsigned char)(res_x >> 8);
	*(info_header + 6) = (unsigned char)(res_x >> 16);
	*(info_header + 7) = (unsigned char)(res_x >> 24);
	*(info_header + 8) = (unsigned char)(res_y);
	*(info_header + 9) = (unsigned char)(res_y >> 8);
	*(info_header + 10) = (unsigned char)(res_y >> 16);
	*(info_header + 11) = (unsigned char)(res_y >> 24);
	*(info_header + 12) = (unsigned char)(1);
	*(info_header + 14) = (unsigned char)(index->current_cam->bpp);
	return (info_header);
}

void					*export_to_bmp(t_rtindex *index)
{
	int				fd;
	unsigned int	img_size;
	unsigned char	*file_header;
	unsigned char	*info_header;

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
