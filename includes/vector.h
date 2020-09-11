/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:21:17 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/11 19:01:48 by danrodri         ###   ########.fr       */
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
#include "structs.h"

t_vector v_add(t_vector v1, t_vector v2);
t_vector v_sub(t_vector v1, t_vector v2);
t_vector v_scalar(t_vector v, float n);
float v_mod(t_vector v);
t_vector v_normalize(t_vector v);
float v_dot(t_vector v1, t_vector v2);
t_vector v_cross(t_vector v1, t_vector v2);
t_vector vmprod(t_vector v, t_vector matrix[3]);
void cam2world_matrix(t_vector forward, t_vector c2w_m[3]);
void obj2world_matrix(t_vector obj_or, t_vector world_or, t_vector o2w_m[3]);
t_vector rot_x(t_vector v, float d);
t_vector rot_y(t_vector v, float d);
t_vector rot_z(t_vector v, float d);

#endif
