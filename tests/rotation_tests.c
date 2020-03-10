/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:10:55 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/10 18:31:29 by danrodri         ###   ########.fr       */
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

float  *world_to_view_matrix(t_vec3d *r, t_vec3d *v_lookat)
{
	float **matrix;
	float v_tmp[3] = {0.0, 1.0, 0.0};
	float v_up[3];
	float v_right[3];

	matrix = malloc((sizeof(float *) * 3) + (sizeof(float) * 9));



	matrix[0][0] = v_lookat->dir[0];
	matrix[0][1] = v_lookat->dir[1];
	matrix[0][2] = v_lookat->dir[2];

	matrix[1][0] = v_
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
