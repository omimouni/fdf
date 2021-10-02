/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:13:31 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/02 17:09:12 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_render_x(int x, int y, int z0, int z1, t_fdf *fdf)
{
	int	buff_x;
	int	buff_y;
	int	nx;
	int	ny;
	t_point	*buff_p;
	t_point	*buff_p_n;

	buff_x = x * fdf->zoom_scale;
	buff_y = y * fdf->zoom_scale;
	buff_p = point_create(buff_x, buff_y, z0);
	f_iso_project(*buff_p, &buff_x, &buff_y);
	nx = (x + 1) * fdf->zoom_scale;
	ny = y * fdf->zoom_scale;
	buff_p_n = point_create(nx, ny, z1);
	f_iso_project(*buff_p_n, &nx, &ny);
	// f_put_pixel(buff_x + fdf->offset_x, buff_y + fdf->offset_y, 0xFFFFFF, fdf);
	f_draw_line(buff_x + fdf->offset_x,
	 buff_y + fdf->offset_y,
	  nx + fdf->offset_x, 
	  ny + fdf->offset_y, 0, fdf);
}

void
	f_render_y(int x, int y, int z0, int z1, t_fdf *fdf)
{
	int	buff_x;
	int	buff_y;
	int	nx;
	int	ny;
	t_point	*buff_p;
	t_point	*buff_p_n;

	buff_x = x * fdf->zoom_scale;
	buff_y = y * fdf->zoom_scale;
	buff_p = point_create(buff_x, buff_y, z0);
	f_iso_project(*buff_p, &buff_x, &buff_y);
	nx = x * fdf->zoom_scale;
	ny = (y + 1) * fdf->zoom_scale;
	buff_p_n = point_create(nx, ny, z1);
	f_iso_project(*buff_p_n, &nx, &ny);
	// f_put_pixel(buff_x + fdf->offset_x, buff_y + fdf->offset_y, 0xFFFFFF, fdf);
	f_draw_line(buff_x + fdf->offset_x,
	 buff_y + fdf->offset_y,
	  nx + fdf->offset_x, 
	  ny + fdf->offset_y, 0, fdf);
}

void
	f_render(t_fdf *fdf)
{
	int	x;
	int	y;
	int	rx;
	int	ry;
	t_point	*p;
	t_point	*np;

	int	fd;
	fd = open("test_maps/test.fdf", O_RDONLY);
	char	*line;
	char	**tab;
	y = 0;
	while (y < fdf->map_h)
	{
		ft_gnl(fd, &line);
		tab = ft_split(line, ' ');
		x = 0;
		while (x < fdf->map_w)
		{
			// TODO: clean up this mess
			// printf("%d %d\n", x, y);
			rx = x * fdf->zoom_scale;
			ry = y * fdf->zoom_scale;
			if (x < fdf->map_w - 1)
				f_render_x(x, y, atoi(tab[x]), atoi(tab[x + 1]), fdf);
			if (y < fdf->map_h - 1)
				f_render_y(x, y, atoi(tab[x]), 0, fdf);
				// f_draw_line(rx, ry, rx, (y +1) * fdf->zoom_scale, 0, fdf);

			
			// f_put_pixel(x * fdf->zoom_scale, y * fdf->zoom_scale, 0xFFFFFF, fdf);
			// f_put_pixel((x + 1) * fdf->zoom_scale, y * fdf->zoom_scale, 0xFF0000, fdf);
			x+=1;
		}
		ft_split_free(tab, fdf->map_w);
		free(line);
		y++;
	}
	close(fd);
}