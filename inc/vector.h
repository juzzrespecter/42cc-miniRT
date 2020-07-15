/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:21:17 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/15 19:46:58 by danrodri         ###   ########.fr       */
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

typedef struct s_3dvec
{
	float orig[4];
	float dir[4];
} t_3dvec;

float length(float v[4]);
float dot(float v1[4], float v2[4]);
void cross(float v1[4], float v2[4], float cross[4]);
void m_v_prod(float v[4], float matrix[4][4], float v_prod[4]);
void matrix_prod(float m1[4][4], float m2[4][4], float m_res[4][4]);
void view_transform(float normal[3], float eye[3], float view_m[4][4]);

#endif
