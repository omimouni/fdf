/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:24:15 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 01:03:34 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_prj_iso_x(int x, int y, t_fdf *fdf)
{
	fdf->line_x = (x * fdf->zoom_scale - y * fdf->zoom_scale) * cos(0.523599);
	fdf->line_y = -fdf->map_z[y][x] + (x * fdf->zoom_scale + y
			* fdf->zoom_scale) * sin(0.523599);
	fdf->line_x_next = ((x + 1) * fdf->zoom_scale - y
			* fdf->zoom_scale) * cos(0.523599);
	fdf->line_y_next = -fdf->map_z[y][x + 1] + ((x + 1)
			* fdf->zoom_scale + y * fdf->zoom_scale) * sin(0.523599);
}

void
	f_prj_iso_y(int x, int y, t_fdf *fdf)
{
	fdf->line_x = (x * fdf->zoom_scale - y * fdf->zoom_scale) * cos(0.523599);
	fdf->line_y = -fdf->map_z[y][x] + (x
			* fdf->zoom_scale + y * fdf->zoom_scale) * sin(0.523599);
	fdf->line_x_next = (x * fdf->zoom_scale
			- (y + 1) * fdf->zoom_scale) * cos(0.523599);
	fdf->line_y_next = -fdf->map_z[y + 1][x]
		+ (x * fdf->zoom_scale + (y + 1) * fdf->zoom_scale) * sin(0.523599);
}

void
	put_line_x(int x, int y, t_fdf *fdf)
{
	f_prj_iso_x(x, y, fdf);
	f_draw_line(
		fdf->line_x + fdf->offset_x,
		fdf->line_y + fdf->offset_y,
		fdf->line_x_next + fdf->offset_x,
		fdf->line_y_next + fdf->offset_y,
		0,
		fdf);
}

void
	put_line_y(int x, int y, t_fdf *fdf)
{
	f_prj_iso_y(x, y, fdf);
	f_draw_line(
		fdf->line_x + fdf->offset_x,
		fdf->line_y + fdf->offset_y,
		fdf->line_x_next + fdf->offset_x,
		fdf->line_y_next + fdf->offset_y,
		0,
		fdf);
}

void
	f_render(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	while (y <= fdf->map_h - 1)
	{
		x = 0;
		while (x <= fdf->map_w - 1)
		{
			if (x < fdf->map_w - 1)
				put_line_x(x, y, fdf);
			if (y < fdf->map_h - 1)
				put_line_y(x, y, fdf);
			x++;
		}
		y++;
	}
}