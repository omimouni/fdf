/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:22:46 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/04 13:06:50 by omimouni         ###   ########.fr       */
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

static void
	f_draw_line_low(int *p, t_fdf *fdf)
{
	int	f[6];

	f[0] = p[2] - p[0];
	f[1] = p[3] - p[1];
	f[2] = 1;
	if (f[1] < 0)
	{
		f[2] = -1;
		f[1] = -f[1];
	}
	f[3] = 2 * f[1] - f[0];
	f[4] = p[1];
	f[5] = p[0];
	while (f[5] < p[2])
	{
		if (f[5] > f[4])
			p[10] = gradient_color(p[7], p[6], percentage(p[0], p[2], f[5]));
		else
			p[10] = gradient_color(p[6], p[7], percentage(p[0], p[2], f[5]));
		f_color_print(f[5], f[4], p, fdf);
		if (f[3] > 0)
		{
			f[4] = f[4] + f[2];
			f[3] = f[3] + (2 * (f[1] - f[0]));
		}
		else
			f[3] = f[3] + 2 * f[1];
		f[5] += 1;
	}
}

static void
	f_draw_line_high(int *p, t_fdf *fdf)
{
	int	f[6];

	f[0] = p[2] - p[0];
	f[1] = p[3] - p[1];
	f[2] = 1;
	if (f[0] < 0)
	{
		f[2] = -1;
		f[0] = -f[0];
	}
	f[5] = 2 * f[0] - f[1];
	f[4] = p[1];
	f[3] = p[0];
	while (f[4] < p[3])
	{
		p[10] = gradient_color(p[6], p[7], percentage(p[1], p[3], f[4]));
		// p[10] = 0xff0000;
		f_color_print(f[3], f[4], p, fdf);
		if (f[5] > 0)
		{
			f[3] = f[3] + f[2];
			f[5] = f[5] + (2 * (f[0] - f[1]));
		}
		else
			f[5] = f[5] + 2 * f[0];
		f[4] += 1;
	}
	printf("\n");
}

void
	f_swap(int *p)
{
	int	x;
	int	y;

	x = p[0];
	y = p[1];
	p[0] = p[2];
	p[1] = p[3];
	p[2] = x;
	p[3] = y;
}

void
	f_draw_line(int *p, t_fdf *fdf)
{
	if (abs(p[3] - p[1]) < abs(p[2] - p[0]))
	{
		if (p[0] > p[2])
			f_swap(p);
		f_draw_line_low(p, fdf);
	}
	else
	{
		if (p[1] > p[3])
			f_swap(p);
		f_draw_line_high(p, fdf);
	}
}
