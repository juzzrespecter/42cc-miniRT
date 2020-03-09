/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:31:59 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/03 18:34:12 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int rgb_conv(unsigned char *rgb_color)
{
	unsigned int color;

	color = (rgb_color[0] + (rgb_color[1] << 8) + (rgb_color[2] << 16)) & 0xffffff;
	return (color);
}
