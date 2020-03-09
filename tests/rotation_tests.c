/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:10:55 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/08 19:39:50 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EH M_PI / 180
//20 degrees in y-axis

float dot(float *vec1, float *vec2)
{
	return ((vec1[0] * vec2[0]) + (vec1[1] * vec2[1]) + (vec1[2] * vec2[2]));
}

float norm(float *vec)
{
	return (sqrt(pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2)));
}

typedef struct s_vec3d
{
	float dir[3];
	float origen[3];
} t_vec3d;

float get_angle(float vec1_1, float vec1_2, float vec2_1, float vec2_2)
{
	float angle;
	float dot = (vec1_1 * vec2_1) + (vec1_2 * vec2_2);
	float det = (vec1_1 * vec2_2) - (vec1_2 * vec2_1);

	angle = atan2(det, dot);
	printf("vector 1: (%f, %f), vector 2: (%f, %f), angulo: %f\n", vec1_1, vec1_2, vec2_1, vec2_2, (angle * 180) / M_PI);
	return (angle);
}

t_vec3d *transformar_rayo(t_vec3d *r, t_vec3d *vo_vec)
{
	float n[3];
	float vec_angle[3];
	float *vo;
	float x, y, z;


	n[0] = 0;
	n[1] = 0;
	n[2] = -1;

	vo = vo_vec->dir;

	vec_angle[0] = get_angle(r->dir[1], r->dir[2], n[1], n[2]);
	vec_angle[1] = get_angle(r->dir[0], r->dir[2], n[0], n[2]);
	vec_angle[2] = get_angle(r->dir[0], r->dir[1], n[0], n[1]);


	printf("init: x(%f) y(%f) z(%f)\n", vo[0], vo[1], vo[2]);

																// x rot
	y = vo[1];
	z = vo[2];
	vo[1] = y * cos(-vec_angle[0]) - z * sin(-vec_angle[0]);
	vo[2] = y * sin(-vec_angle[0]) + z * cos(-vec_angle[0]);

	printf("rot x: x(%f) y(%f) z(%f)\n", vo[0], vo[1], vo[2]);

																// y rot
	x = vo[0];
	z = vo[2];
	vo[0] = x * cos(-vec_angle[1]) + z * sin(-vec_angle[1]);
	vo[2] = x * -sin(-vec_angle[1]) + z * cos(-vec_angle[1]);

	printf("rot y: x(%f) y(%f) z(%f)\n", vo[0], vo[1], vo[2]);

																// z rot
	x = vo[0];
	y = vo[1];
	vo[0] = x * cos(-vec_angle[2]) - z * sin(-vec_angle[2]);
	vo[1] = x * sin(-vec_angle[2]) - z * cos(-vec_angle[2]);

	printf("rot z: x(%f) y(%f) z(%f)\n", vo[0], vo[1], vo[2]);


	r->dir[0] = vo[0];
	r->dir[1] = vo[1];
	r->dir[2] = vo[2];
	return (r);
}

int main()
{
	// vamos a rotar una cámara

	float pixel_ndc[3];
	float pixel_screen[3];
	float pixel_camera[3];
	t_vec3d *rayo;
	t_vec3d *vector_de_orientacion;
	float ratio;
	float fov = 45;
	int x = 0, y = 0;
	int res_x = 3, res_y = 3;
	float vdo_length;
	float dir_length;

	vector_de_orientacion = malloc(sizeof(t_vec3d));

	vector_de_orientacion->dir[0] = 0;
	vector_de_orientacion->dir[1] = 0;
	vector_de_orientacion->dir[2] = 1;

	vdo_length = norm(vector_de_orientacion->dir);

	vector_de_orientacion->dir[0] /= vdo_length;
	vector_de_orientacion->dir[1] /= vdo_length;
	vector_de_orientacion->dir[2] /= vdo_length;

	vector_de_orientacion->origen[0] = 0;
	vector_de_orientacion->origen[1] = 0;
	vector_de_orientacion->origen[2] = 0;

	while (y < res_x)
		{
			printf("row (%d):\n", y);
		 while (x < res_y)
				{
					ratio = res_x / res_y;
					pixel_ndc[0] = (x + 0.5) / res_x;
					pixel_screen[0] = 2 * pixel_ndc[0] - 1;
					pixel_camera[0] = pixel_screen[0] * ratio * tan(((fov / 2) * M_PI) / 180);

					pixel_ndc[1] = (y + 0.5) / res_y;
					pixel_screen[1] = 1 - 2 * pixel_ndc[1];
					pixel_camera[1] = pixel_screen[1] * tan(((fov / 2) * M_PI) / 180);

					pixel_camera[2] = -1;
					rayo = malloc(sizeof(t_vec3d));

					rayo->dir[0] = pixel_camera[0];
					rayo->dir[1] = pixel_camera[1];
					rayo->dir[2] = pixel_camera[2];

					dir_length = norm(rayo->dir);

					rayo->dir[0] /= dir_length;
					rayo->dir[1] /= dir_length;
					rayo->dir[2] /= dir_length;

					rayo->origen[0] = 0;
					rayo->origen[1] = 0;
					rayo->origen[2] = 0;

					printf("n: x(%f) y(%f) z(%f)\n", rayo->dir[0], rayo->dir[1], rayo->dir[2]);
					rayo = transformar_rayo(rayo, vector_de_orientacion);
					printf("t: x(%f) y(%f) z(%f)\n\n", rayo->dir[0], rayo->dir[1], rayo->dir[2]);
					x++;
				}
		 printf("\n");
				y++;
			x = 0;
		}
}
