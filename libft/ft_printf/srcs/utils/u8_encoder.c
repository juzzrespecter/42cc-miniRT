/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u8_encoder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:26:32 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/01 20:54:22 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	get_csize(wchar_t u8char)
{
	if (u8char <= 0x7f)
		return (2);
	if (u8char <= 0x7ff)
		return (3);
	if (u8char <= 0xffff)
		return (4);
	if (u8char <= 0x10ffff)
		return (5);
	return (0);
}

static void	gt0x7f(char *u8char_str, wchar_t u8char)
{
	u8char_str[0] = (char)(((u8char >> 6) & 0x1f) | 0xc0);
	u8char_str[1] = (char)(((u8char >> 0) & 0x3f) | 0x80);
}

static void	gt0x7ff(char *u8char_str, wchar_t u8char)
{
	u8char_str[0] = (char)(((u8char >> 12) & 0x0f) | 0xe0);
	u8char_str[1] = (char)(((u8char >> 6) & 0x3f) | 0x80);
	u8char_str[2] = (char)(((u8char >> 0) & 0x3f) | 0x80);
}

static void	gt0xffff(char *u8char_str, wchar_t u8char)
{
	u8char_str[0] = (char)(((u8char >> 18) & 0x07) | 0xf0);
	u8char_str[1] = (char)(((u8char >> 12) & 0x3f) | 0x80);
	u8char_str[2] = (char)(((u8char >> 6) & 0x3f) | 0x80);
	u8char_str[3] = (char)(((u8char >> 0) & 0x3f) | 0x80);
}

char		*u8_encoder(wchar_t u8char)
{
	char *u8char_str;

	if (!(u8char_str = malloc(sizeof(char) * get_csize(u8char))))
		return (0);
	if (u8char <= 0x7f)
		u8char_str[0] = (char)u8char;
	if (u8char > 0x7f && u8char <= 0x7ff)
		gt0x7f(u8char_str, u8char);
	if (u8char > 0x7ff && u8char <= 0xffff)
		gt0x7ff(u8char_str, u8char);
	if (u8char > 0xffff && u8char <= 0x10ffff)
		gt0xffff(u8char_str, u8char);
	u8char_str[get_csize(u8char) - 1] = 0;
	return (u8char_str);
}
