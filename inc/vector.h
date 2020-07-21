/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:21:17 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/21 18:02:26 by danrodri         ###   ########.fr       */
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
	float coord_col[3];
	unsigned int color_col;
	bool found_col;
} t_3dvec;

float length(float *v);
float dot(float *v1, float *v2);
void cross(float *v1, float *v2, float *cross);
void m_v_prod(float v[4], float matrix[4][4], float v_prod[4]);
void normalize(float *v);
void matrix_prod(float m1[4][4], float m2[4][4], float m_res[4][4]);
void set_id_matrix(float matrix[4][4]);
void wtov_transform(float normal[3], float eye[3], float wtov_m[4][4]);
void ctow_transform(float *forward, float *eye, float ctow_m[4][4]);
void otow_transform(float *ov_obj, float *ov_world, float *c_world, float otow_m[4][4]);

#endif
