/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:21:17 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/14 19:49:40 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//aqui van todas las funciones de calculos de vectores y matrices
//calculos entre vectores
//calculos entre matrices??
//transformaciones: escala, traslacion, rotacion
//mirar cuaterniones para evitar el 'gimbal lock'

//matrices: model matrix (modeltoworld), view matrix (worldtoview)

#ifndef VECTOR_H
#define VECTOR_H

typedef struct s_3dvec
{
	float orig[4];
	float dir[4];
} t_3dvec;

float length(t_3dvec v);
float dot(t_3dvec v1, t_3dvec v2);
t_3dvec cross(t_3dvec v1, t_3dvec v2);
t_3dvec m_v_prod(t_3dvec v, float matrix[4][4]);

#endif
