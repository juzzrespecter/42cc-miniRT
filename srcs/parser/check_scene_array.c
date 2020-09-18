/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:24:24 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/18 19:49:01 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool check_scene_array(char **scene_line, int n_lines)
{
	int i;

	i = 0;
	while (scene_line[i])
		i++;
	return (i == n_lines ? true : false);
}
