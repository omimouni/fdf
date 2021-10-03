/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:22:46 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 00:41:48 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void
	f_draw_line_low(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	y;
	int	x;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	y = y0;
	x = x0;
	while (x < x1)
	{
		f_put_pixel(x, y, 0xffffff, fdf);
		if (d > 0)
		{
			y = y + yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + 2 * dy;
		x++;
	}
}

static void
	f_draw_line_high(int x0, int y0, int x1, int y1, t_fdf *fdf)
{

	int	dx;
	int	dy;
	int	xi;
	int	x;
	int	y;
	int	d;

	xi = 1;
	dx = x1 - x0;
	dy = y1 - y0;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	y = y0;
	x = x0;
	while (y < y1)
	{
		f_put_pixel(x, y, 0xffffff, fdf);
		if (d > 0)
		{
			x = x + xi;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + 2 * dx;
		y++;
	}
}


void
	f_draw_line(int x0, int y0, int x1, int y1, int z, t_fdf *fdf)
{	
	// TODO: Check out of bound
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			f_draw_line_low(x1, y1, x0, y0, fdf);
		else
			f_draw_line_low(x0, y0, x1, y1, fdf);
	}
	else
	{
		if (y0 > y1)
			f_draw_line_high(x1, y1, x0, y0, fdf);
		else
			f_draw_line_high(x0, y0, x1, y1, fdf);
	}
}
