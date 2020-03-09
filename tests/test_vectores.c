/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vectores.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:12:25 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/02 16:52:21 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "testlib.h"

double ft_max(double a, double b)
{
	return ((a > b) ? a : b);
}

double ft_min(double a, double b)
{
	return ((a < b) ? a : b);
}

double dot(float *vec1, float *vec2)
{

	return ((vec1[0] * vec2[0]) + (vec1[1] * vec2[1]) + (vec1[2] * vec2[2]));
}

double norm(float *vector)
{
	return (sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2)));
}

unsigned int test_phong(amb amb, light light, unsigned char color[3], float *normal, float *p)
{
	unsigned int c;
	unsigned char light_color[3];
	float amb_color[3];
	float diff_color[3];
	float light_ray[3];
	float mod_light;
	float mod_normal;

	//printf("light pos: l_x (%lf), l_y (%lf), l_z (%lf)\n", light.pos[0], light.pos[1], light.pos[2]);
	light_color[0] = color[0];
	light_color[1] = color[1];
	light_color[2] = color[2];

	c = (light_color[0] + (light_color[1] << 8) + (light_color[2] << 16)) & 0xffffff;

	printf("color_red (%d), color_green (%d), color_blue (%d)\nINIC color (%#x)\n", color[0], color[1], color[2], c);

	light_ray[0] = light.pos[0] - p[0];
	light_ray[1] = light.pos[1] - p[1];
	light_ray[2] = light.pos[2] - p[2];

	mod_light = norm(light_ray);
	mod_normal = norm(normal);

	light_ray[0] /= mod_light;
	light_ray[1] /= mod_light;
	light_ray[2] /= mod_light;

	normal[0] /= mod_normal;
	normal[1] /= mod_normal;
	normal[2] /= mod_normal;

	//printf("light ray: x (%f), y (%f), z (%f)\n", light_ray[0], light_ray[1], light_ray[2]);
	//	printf("normal: x (%lf), y (%lf), z (%lf)\n\n", normal[0], normal[1], normal[2]);

	amb_color[0] = (amb.color[0] / 255) * amb.bright;
	amb_color[1] = (amb.color[1] / 255) * amb.bright;
	amb_color[2] = (amb.color[2] / 255) * amb.bright;

	printf("amb color: %f, %f, %f -- ", amb_color[0], amb_color[1], amb_color[2]);

	//printf("producto escalar: (%lf)\n\n", dot(light_ray, normal));
	diff_color[0] = (light.color[0] / 255) * light.l_int * (ft_max(dot(light_ray, normal), 0.0));
	diff_color[1] = (light.color[1] / 255) * light.l_int * (ft_max(dot(light_ray, normal), 0.0));
	diff_color[2] = (light.color[2] / 255) * light.l_int * (ft_max(dot(light_ray, normal), 0.0));

	printf("diff color: %f, %f, %f\n", diff_color[0], diff_color[1], diff_color[2]);

	light_color[0] = color[0] * (ft_min((diff_color[0] * 255) + (amb_color[0] * 255), 255.0) / 255);
	light_color[1] = color[1] * (ft_min((diff_color[1] * 255) + (amb_color[1] * 255), 255.0) / 255);
	light_color[2] = color[2] * (ft_min((diff_color[2] * 255) + (amb_color[2] * 255), 255.0) / 255);

	/*light_color[0] = 255 * (ft_min((diff_color[0] * 255) + (amb_color[0] * 255), 255.0) / 255);
	light_color[1] = 255 * (ft_min((diff_color[1] * 255) + (amb_color[1] * 255), 255.0) / 255);
	light_color[2] = 255 * (ft_min((diff_color[2] * 255) + (amb_color[2] * 255), 255.0) / 255);*/

	printf("light color: %d, %d, %d\n", light_color[0], light_color[1], light_color[2]);

	c = (light_color[0] + (light_color[1] << 8) + (light_color[2] << 16)) & 0xffffff;

	printf("%#x\n\n\n", c);

	return (c);
}

vector ray_maker(float *cam_pos, float *pixel_pos)
{
	vector ray;
	double mod;

	ray.orig[0] = cam_pos[0];
	ray.orig[1] = cam_pos[1];
	ray.orig[2] = cam_pos[2];

	ray.dir[0] = pixel_pos[0];
	ray.dir[1] = pixel_pos[1];
	ray.dir[2] = pixel_pos[2];

	//printf("PRE dir x (%lf), dir y (%lf), dir z (%lf)\n", ray.dir[0], ray.dir[1], ray.dir[2]);
	mod = norm(ray.dir);
	//printf("mod: (%lf)\n", mod);
	ray.dir[0] /= mod;
	ray.dir[1] /= mod;
	ray.dir[2] /= mod;
	//printf("POST dir x (%lf), dir y (%lf), dir z (%lf)\n\n\n", ray.dir[0], ray.dir[1], ray.dir[2]);

	return (ray);
}

unsigned int test_collision(vector rayo, sp s, light light, amb amb)
{
	float sqrt_ec;
	float d[2];
	float r;
	float p[3];
	float oc[3];
	float normal[3];

	oc[0] = rayo.orig[0] - s.pos[0];
	oc[1] = rayo.orig[1] - s.pos[1];
	oc[2] = rayo.orig[2] - s.pos[2];

	r = s.radio / 2;

	sqrt_ec = pow(dot(rayo.dir, oc), 2) - (pow(norm(oc), 2) - pow(r, 2));
	//	printf("sqrt_ec (%f) = %f - %f\n", sqrt_ec, pow(dot(rayo.dir, oc), 2), (norm(oc) - pow(r, 2)));
	//printf("rayo.dir_x: (%lf), rayo.dir_y: (%lf), rayo.dir_z: (%lf)\n", rayo.dir[0], rayo.dir[1], rayo.dir[2]);
	//printf("oc_x: (%lf), oc_y: (%lf), oc_z: (%lf)\n\n", oc[0], oc[1], oc[2]);
	//	printf("dot(...) = (%lf)\n", dot(rayo.dir, oc));

	if (sqrt_ec < 0)
		return (0);
	if (!sqrt_ec)
		{
			d[0] = -(dot(rayo.dir, oc));

			p[0] = rayo.orig[0] + d[0] * rayo.dir[0];
			p[1] = rayo.orig[1] + d[0] * rayo.dir[1];
			p[2] = rayo.orig[2] + d[0] * rayo.dir[2];

			normal[0] = p[0] - s.pos[0];
			normal[1] = p[1] - s.pos[1];
			normal[2] = p[2] - s.pos[2];

			return (test_phong(amb, light, s.color, normal, p));
		}
	else
		{
			d[0] = -(dot(rayo.dir, oc)) - sqrt(sqrt_ec);
			d[1] = -(dot(rayo.dir, oc)) + sqrt(sqrt_ec);

			((d[0] > d[1]) ? (d[0] = d[1]) : (d[0] = d[0]));

			p[0] = rayo.orig[0] + d[0] * rayo.dir[0];
			p[1] = rayo.orig[1] + d[0] * rayo.dir[1];
			p[2] = rayo.orig[2] + d[0] * rayo.dir[2];

			//printf("punto en el que corta: x (%f), y (%f), z (%f)\n", p[0], p[1], p[2]);
			normal[0] = p[0] - s.pos[0];
			normal[1] = p[1] - s.pos[1];
			normal[2] = p[2] - s.pos[2];

			return (test_phong(amb, light, s.color, normal, p));
		}
}

void test(data *data)
{
	//prueba de colisiones entre rayo y objeto
	sp s;
	amb amb;
	light light;
	int	res_x = data->res_x;
	int	res_y = data->res_y;
	int x = 0, y = 0;
	//	int cam_canv_d;
	vector rayo;
	float ratio;
	float pixelNDC[3];
	float pixelScreen[3];
	float pixelCamera[3];
	int bits_per_pixel, endian, size_line, i;
	char *img;

	img = mlx_get_data_addr(data->img_ptr, &bits_per_pixel, &size_line, &endian);

	ratio = (float)res_x / (float)res_y;

	s.pos[0] = 0;
	s.pos[1] = 20;
	s.pos[2] = 100;

	s.radio = 30;

	s.color[0] = 0;
	s.color[1] = 0;
	s.color[2] = 255;

	amb.bright = 0.2;

	amb.color[0] = 255;
	amb.color[1] = 255;
	amb.color[2] = 255;

	light.color[0] = 255;
	light.color[1] = 255;
	light.color[2] = 255;

	light.l_int = 0.5;

	light.pos[0] = 50;
	light.pos[1] = 100;
	light.pos[2] = -60;

	//cam_canv_d = (res_x / 2) / tan(c1.fov / 2);

	//generador de rayo
	while (y < res_y)
		{
			while (x < res_x)
				{
					pixelNDC[0] = (x + 0.5) / res_x;
					pixelNDC[1] = (y + 0.5) / res_y;

					pixelScreen[0] = 2 * pixelNDC[0] - 1;
					pixelScreen[1] = 1 - 2 * pixelNDC[1];

					pixelCamera[0] = pixelScreen[0] * ratio * tan(((data->cam.fov / 2) * M_PI) / 180);
					pixelCamera[1] = pixelScreen[1] * tan(((data->cam.fov / 2) * M_PI) / 180);
					pixelCamera[2] = 1;

					//					printf("pixel_x (%f) = %f * %f * %f\n", pixelCamera[0], pixelScreen[0], ratio, tan(data->cam.fov / 2));

					rayo = ray_maker(data->cam.pos, pixelCamera);
					i = x * (bits_per_pixel / 8) + (y * size_line);
					*(unsigned int *)(img + i) = test_collision(rayo, s, light, amb);
					x++;
					//	printf("pixel ndc: %f, %f, %f\n", pixelNDC[0], pixelNDC[1], pixelNDC[2]);
					//	printf("pixel screen: %f, %f, %f\n", pixelScreen[0], pixelScreen[1], pixelScreen[2]);
					//	printf("pixel camera: %f, %f, %f\n", pixelCamera[0], pixelCamera[1], pixelCamera[2]);
				}
			x = 0;
			y++;
		}
}
