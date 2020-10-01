/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:27:23 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/01 21:06:11 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "structs.h"

t_objs		*scene_parser(char *scene_file, t_rt *index);
bool		check_scene_array(char **scene_line, int n_lines);
bool		res_error_check(char **scene_line);
bool		light_check(char *light);
bool		color_check(char *color);
bool		coord_check(char *coord);
bool		vector_check(char *vector);
bool		dim_check(char *dim);
float		array_to_float(char *array);
t_vector	array_to_vector(char *array);
t_color		array_to_color(char *color);
bool		build_sphere(char **scene_line, t_objs *o_lst);
bool		build_amb(char **scene_line, t_objs *o_lst);
bool		build_cylinder(char **scene_line, t_objs *o_lst);
bool		build_res(char **scene_line, t_rt *index);
bool		build_triangle(char **scene_line, t_objs *o_lst);
bool		build_light(char **scene_line, t_objs *o_lst);
bool		build_cam(char **scene_line, t_rt *index);
bool		build_plane(char **scene_line, t_objs *o_lst);
bool		build_square(char **scene_line, t_objs *o_lst);
bool		build_triangle(char **scene_line, t_objs *o_lst);

#endif
