/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:21:17 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/13 19:44:06 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//aqui van todas las funciones de calculos de vectores y matrices
//calculos entre vectores
//calculos entre matrices??
//transformaciones: escala, traslacion, rotacion
//mirar cuaterniones para evitar el 'gimbal lock'

#ifndef VECTOR_H
#define VECTOR_H

typedef struct s_3dvec
{
	float orig[3];
	float dir[3];
} t_3dvec;

#endif
