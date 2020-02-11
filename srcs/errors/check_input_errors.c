/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:41:29 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 20:08:27 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int largest_str(char *s1, char *s2)
{
	int len_s1;
	int len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	return ((len_s1 > len_s2) ? len_s1 : len_s2);
}

int check_input_errors(t_obj *lst)
{
	int all_ok;

	all_ok = 1;
	while (lst)
		{
			if (!ft_strncmp(lst->id, "R", largest_str(lst->id, "R")))
				all_ok = res_error(lst);
			if (!ft_strncmp(lst->id, "A", largest_str(lst->id, "A")))
				all_ok = amb_error(lst);
			if (!ft_strncmp(lst->id, "c", largest_str(lst->id, "c")))
				all_ok = camera_error(lst);
			if (!ft_strncmp(lst->id, "l", largest_str(lst->id, "l")))
				all_ok = light_error(lst);
			if (!ft_strncmp(lst->id, "sp", largest_str(lst->id, "sp")))
				all_ok = sphere_error(lst);
			if (!ft_strncmp(lst->id, "sq", largest_str(lst->id, "sq")))
				all_ok = square_error(lst);
			if (!ft_strncmp(lst->id, "pl", largest_str(lst->id, "pl")))
				all_ok = plane_error(lst);
			if (!ft_strncmp(lst->id, "cy", largest_str(lst->id, "cy")))
				all_ok = cylinder_error(lst);
			if (!ft_strncmp(lst->id, "tr", largest_str(lst->id, "tr")))
				all_ok = triangle_error(lst);
			if (!all_ok)
				return (0);
			lst = lst->next;
		}
	return (1);
}
