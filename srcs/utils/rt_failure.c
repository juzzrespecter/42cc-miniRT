/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_failure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:03:03 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/09 17:04:54 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void rt_failure(t_olst *olst, char *err_msg)
{
	ft_printf("%s\n", err_msg);
	delete_olst(olst);
	exit(EXIT_FAILURE);
}
