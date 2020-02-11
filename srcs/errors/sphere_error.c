/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:07:23 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/10 19:16:27 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int sphere_error(t_obj *sp_obj)
{
	char *coords;
	char *d;
	char *colors;

	coords = sp_obj->content[0];
	d = sp_obj->content[1];
	colors = sp_obj->content[2];
	return ((!sp_obj->content[3] && coords_error(coords) && prop_error(d) && colors_error(colors)) ? 1 : 0);
}
