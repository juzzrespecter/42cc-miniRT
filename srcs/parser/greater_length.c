/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 20:19:57 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/31 20:21:37 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int greater_length(char *s1, char *s2)
{
	int s1_len;
	int s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	return (s1_len > s2_len ? s1_len : s2_len);
}
