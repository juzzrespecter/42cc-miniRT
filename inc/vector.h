/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:21:17 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/29 19:23:41 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//aqui van todas las funciones de calculos de vectores y matrices
//calculos entre vectores
//calculos entre matrices??
//transformaciones: escala, traslacion, rotacion
//mirar cuaterniones para evitar el 'gimbal lock'

//matrices: model matrix (modeltoworld), view matrix (worldtoview)
//lookat -> camtoworld matrix -> view matrix
//escalar -> rotar -> transladar

//column vectors??


#ifndef VECTOR_H
#define VECTOR_H
#include <stdbool.h>
#include <math.h>

typedef struct s_3dvec
{
	float orig[4];
	float dir[4];
	float point_coord[3];
	float normal_vector[3];
	unsigned char point_color[3];
	bool point_found;
} t_3dvec;

float length(float *v);
float dot(float *v1, float *v2);
void cross(float *v1, float *v2, float *cross);
void norm(float *v);
void vmprod(float v[4], float matrix[4][4], float v_prod[4]);
void mprod(float m1[4][4], float m2[4][4], float m_res[4][4]);
void set_id_matrix(float matrix[4][4]);
void cam2world_matrix(float *forward, float *eye, float c2w_m[4][4]);
void obj2world_matrix(float *orig, float *obj_or, float *world_or, float o2w_m[4][4]);
void translate(float *point, float *move);

#endif
