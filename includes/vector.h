/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:21:17 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/01 21:25:46 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdbool.h>
# include <math.h>
# include "structs.h"

t_vector	v_add(t_vector v1, t_vector v2);
t_vector	v_sub(t_vector v1, t_vector v2);
t_vector	v_scalar(t_vector v, float n);
float		v_mod(t_vector v);
t_vector	v_normalize(t_vector v);
float		v_dot(t_vector v1, t_vector v2);
t_vector	v_cross(t_vector v1, t_vector v2);
t_vector	vmprod(t_vector v, t_matrix matrix);
t_matrix	matrix_cam2world(t_vector forward);
t_matrix	matrix_obj2world(t_vector obj_or, t_vector world_or);
t_vector	rot_x(t_vector v, float d);
t_vector	rot_y(t_vector v, float d);
t_vector	rot_z(t_vector v, float d);

#endif
