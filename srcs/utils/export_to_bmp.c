/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_to_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:11:04 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/30 22:17:18 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static unsigned char	*file_header(t_bmp *bmp)
{
	int				file_size;
	unsigned char	*file_header;

	if (!(file_header = malloc(FILE_HEADER_SIZE * sizeof(unsigned char))))
		return (NULL);
	ft_bzero(file_header, FILE_HEADER_SIZE);
	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + bmp->imgsize;
	*file_header = (unsigned char)0x42;
	*(file_header + 1) = (unsigned char)0x4D;
	*(file_header + 2) = (unsigned char)file_size;
	*(file_header + 3) = (unsigned char)(file_size >> 8);
	*(file_header + 4) = (unsigned char)(file_size >> 16);
	*(file_header + 5) = (unsigned char)(file_size >> 24);
	*(file_header + 10) = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	return (file_header);
}

static unsigned char	*info_header(t_bmp *bmp)
{
	unsigned char *info_header;

	if (!(info_header = malloc(INFO_HEADER_SIZE * sizeof(unsigned char))))
		return (NULL);
	ft_bzero(info_header, INFO_HEADER_SIZE);
	*info_header = (unsigned char)INFO_HEADER_SIZE;
	*(info_header + 4) = (unsigned char)(bmp->height);
	*(info_header + 5) = (unsigned char)(bmp->height >> 8);
	*(info_header + 6) = (unsigned char)(bmp->height >> 16);
	*(info_header + 7) = (unsigned char)(bmp->height >> 24);
	*(info_header + 8) = (unsigned char)(bmp->width);
	*(info_header + 9) = (unsigned char)(bmp->width >> 8);
	*(info_header + 10) = (unsigned char)(bmp->width >> 16);
	*(info_header + 11) = (unsigned char)(bmp->width >> 24);
	*(info_header + 12) = (unsigned char)(1);
	*(info_header + 14) = (unsigned char)(bmp->bits_per_pixel);
	return (info_header);
}

static char				*filename(char *name)
{
	char *bmpfilename;
	char *aux;
	char *start;

	start = ft_strchr(name, '/');
	start = (!start) ? name : start + 1;
	if (!(bmpfilename = ft_substr(start, 0, (ft_strchr(name, '.') - start))))
		return (NULL);
	aux = bmpfilename;
	if (!(bmpfilename = ft_strjoin(bmpfilename, ".bmp")))
		return (NULL);
	free(aux);
	return (bmpfilename);
}

static void				img_to_bmp(int fd, t_bmp *index)
{
	int i;

	i = 0;
	while (i < bmp->height)
	{
		write(fd, bmp->img[imgsize - (i * bmp->width_bytes)], bmp->width_bytes);
		write(fd, "\0\0\0\0", bmp->padding);
		i++;
	}
}

void					export_to_bmp(t_rtindex *index, char *rtname)
{
	int				fd;
	t_bmp			bmp;

	ft_bzero(&bmp, sizeof(t_bmp));
	if (!(bmp.filename = filename(rtname)))
		exit_failure(index, "Error: malloc couldn't assign dynamic memory.");
	fd = open(bmp.filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	free(bmp.filename);
	bmp.width = index->res_x;
	bmp.height = index->res_y;
	bmp.bits_per_pixel = index->current_cam->bpp;
	bmp.img = index->current_cam->img;
	bmp.width_bytes = bmp.width * bmp.bits_per_pixel;
	//bmp.padding = (bmp.width_bytes % 4) ? (4 - bmp.width_bytes % 4) : 0;
	bmp.padding = 3;
	if (fd < 0)
		exit_failure(index, "Error: failed to create .bmp file.");
	if (!(bmp.fileheader = file_header(&bmp)))
		exit_failure(index, "Error: malloc couldn't assign dynamic memory.");
	write(fd, bmp.fileheader, FILE_HEADER_SIZE);
	free(bmp.fileheader);
	if (!(bmp.infoheader = info_header(&bmp)))
		exit_failure(index, "Error: malloc couldn't assign dynamic memory.");
	write(fd, bmp.infoheader, INFO_HEADER_SIZE);
	free(bmp.infoheader);
	img_to_bmp(fd, &bmp);
	close(fd);
	//exit_success(index);
	//meter una variable fd dentro de la estructura index
}
