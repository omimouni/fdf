/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:22:46 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 12:44:17 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
