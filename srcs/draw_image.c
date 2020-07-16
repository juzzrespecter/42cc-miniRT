/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:49:37 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/16 19:25:40 by danrodri         ###   ########.fr       */
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
//
//el vector direccion dell rayo esta en el espacio objeto de la camara,
//hay que transformarlo con m_cam_to_world en coordenadas de espacio mundo
//point (o algun identificador de colision) en la estructura rayo??

void cam_to_world_transform(float ctow_m[4][4], t_cam *cam)
{

}

static t_3dvec *build_ray(float x, float y, t_cam *cam)
{
	float ctow_m[4][4];
	t_3dvec *ray;
	int z;

	if (!(ray = malloc(sizeof(t_3dvec))))
		return (NULL);
	ray->found_col = false;
	z = -1;
	cam_to_world_transform(ctow_m, cam);
	return (ray);
}

static float x_pixel(t_data data, int x, int fov)
{
	float x_pixel;
}

static float y_pixel(t_data data, int y, int fov)
{
	float y_pixel;
}

char *draw_image(t_objlst *obj_lst, t_data data, char *img)
{
	t_3dvec *ray;
	int fov;
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	fov = obj_lst->cam->fov;
	while (data.x_res < x)
		{
			while (data.y_res < y)
				{
					i = (x * (data.bits_per_pixel / 8) + (y * data.size_line));
					ray = build_ray(x_pixel(data, x, fov), y_pixel(data, y, fov), obj_lst->cam);
					search_for_collision(obj_lst, ray);
					*(unsigned int *)(img + i) = get_pixel_color(obj_lst->light, &ray);
				}
		}
	return (img);
}
