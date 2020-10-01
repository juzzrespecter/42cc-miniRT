/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_to_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:11:04 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/01 20:22:15 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		file_header(t_bmp *bmp, int fd)
{
	int				file_size;
	unsigned char	file_header[FILE_HEADER_SIZE];

	ft_bzero(file_header, FILE_HEADER_SIZE);
	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + bmp->imgsize;
	*file_header = (unsigned char)0x42;
	*(file_header + 1) = (unsigned char)0x4D;
	*(file_header + 2) = (unsigned char)file_size;
	*(file_header + 3) = (unsigned char)(file_size >> 8);
	*(file_header + 4) = (unsigned char)(file_size >> 16);
	*(file_header + 5) = (unsigned char)(file_size >> 24);
	*(file_header + 10) = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	write(fd, file_header, FILE_HEADER_SIZE);
}

static void		info_header(t_bmp *bmp, int fd)
{
	unsigned char info_header[INFO_HEADER_SIZE];

	ft_bzero(info_header, INFO_HEADER_SIZE);
	*info_header = (unsigned char)INFO_HEADER_SIZE;
	*(info_header + 4) = (unsigned char)(bmp->width);
	*(info_header + 5) = (unsigned char)(bmp->width >> 8);
	*(info_header + 6) = (unsigned char)(bmp->width >> 16);
	*(info_header + 7) = (unsigned char)(bmp->width >> 24);
	*(info_header + 8) = (unsigned char)(bmp->height);
	*(info_header + 9) = (unsigned char)(bmp->height >> 8);
	*(info_header + 10) = (unsigned char)(bmp->height >> 16);
	*(info_header + 11) = (unsigned char)(bmp->height >> 24);
	*(info_header + 12) = (unsigned char)(1);
	*(info_header + 14) = (unsigned char)(bmp->bpp);
	write(fd, info_header, INFO_HEADER_SIZE);
}

static char		*filename(char *name)
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

static int		init_bmp_info(t_bmp *bmp, t_rt *index, char *rtname)
{
	char	*bmpname;
	int		fd;

	if (!(bmpname = filename(rtname)))
		exit_failure(index, "Error: malloc couldn't assign dynamic memory.");
	fd = open(bmpname, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	free(bmpname);
	if (fd < 0)
		exit_failure(index, "Error: failed to create .bmp file.");
	bmp->height = index->res_y;
	bmp->width = index->res_x;
	bmp->bpp = index->current_cam->bpp;
	bmp->img = index->current_cam->img;
	bmp->sl = index->current_cam->sl;
	bmp->imgsize = bmp->width * bmp->sl;
	file_header(bmp, fd);
	info_header(bmp, fd);
	return (fd);
}

void			export_to_bmp(t_rt *index, char *rtname)
{
	int		x;
	int		y;
	int		i;
	int		fd;
	t_bmp	bmp;

	ft_bzero(&bmp, sizeof(t_bmp));
	fd = init_bmp_info(&bmp, index, rtname);
	x = 0;
	y = 0;
	while (y < bmp.height)
	{
		while (x < bmp.width)
		{
			i = (x * (bmp.bpp / 8) + ((bmp.height - y - 1) * bmp.sl));
			write(fd, &bmp.img[i], 4);
			x++;
		}
		y++;
		x = 0;
	}
	close(fd);
	exit_success(index);
}
