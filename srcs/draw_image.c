/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:49:37 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/15 20:26:45 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//creo bucle que, para cada pixel de la imagen calcule un punto de la
//camara y lance un rayo por este
//
//llama a search_for_collision, que calcula con el rayo lanzado
//la posible colision con cada uno de los objetos definidos en la lista
//
//dos opciones: struct point que sea una lista que almacene todas las
//colisiones y luego se criba por distancia con la camara (o pixel?)
//o se gestiona la colision mas cercana de manera dinamica mientras se
//calculan colisiones
//
//devuelve la colision si la hubiera, y llamo a search_for_light para
//encontrar el color definitivo que se almacena en (*img + i)
//se calcula vector con cada una de las fuentes de luz y la colision
//y se vuelve a iterar con la lista de objetos en escena para encontrar sombras
//si un objeto corta la ruta de la luz hacia la colision, se descarta
//si no se encuentran sombras entre varias fuentes de luz, se suman entre ellas
//si no hay fuentes de luz que impactan de forma directa con la colision
//guardamos unicamente el color ambiente
//
//devuelve (unsigned int) color (codificado) y se guarda en *img

char *draw_image(t_objlst *obj_lst, t_data data, char *img)
{
	t_point point;
	t_3dvec ray;
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (data.x_res < x)
		{
			while (data.y_res < y)
				{
					i = (x * (data.bits_per_pixel / 8) + (y * data.size_line));
					ray.dir[0] = ;
					//pixel - y coord
					ray.dir[1] = ;
					//pixel - z coord
					ray.dir[2] = -1;
					point = search_for_collision(obj_lst, ray);
					*(unsigned int *)(img + i) = get_pixel_color(obj_lst->light, point);
				}
		}
	return (img);
}
