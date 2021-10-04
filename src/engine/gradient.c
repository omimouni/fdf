/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 12:27:09 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/04 17:35:34 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int
	get_shade(int start, int end, double per)
{
	return ((int)((1 - per) * start + per * end));
}

int
	gradient_color(int c1, int c2, double p)
{
	int	rgb[3];

	rgb[0] = get_shade((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	rgb[1] = get_shade((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	rgb[2] = get_shade(c1 & 0xFF, c2 & 0xFF, p);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

double
	percentage(int start, int end, int current)
{
	double	place;
	double	d;

	d = (double)end - (double)start;
	place = (double)current - (double)start + 1;
	if (d == 0)
		return (1);
	return (place / d);
}

void
	f_color_print(int x, int y, int *p, t_fdf *fdf)
{
	f_put_pixel(x, y, p[10], fdf);
}
