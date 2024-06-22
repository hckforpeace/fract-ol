/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bitshift.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:14:46 by pierre            #+#    #+#             */
/*   Updated: 2024/06/22 14:38:09 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Bit Shifting | is or binary '<< x' means left shift addind x:0 before aka shifting to the left*/
/* reversing the process herw we want to retreive the T which is the transparency */
int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}
/* same for red */
int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}
/* same for green */
int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}
/* same for blue */
int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	invert(int	color)
{
	int	r;
	int	g;
	int	b;
	int	t;

	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	t = get_t(color);
	return (create_trgb(t, 255 - r, 255 - g, 255 - b));
}
