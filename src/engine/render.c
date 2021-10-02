/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:13:31 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/02 15:35:06 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_render(t_fdf *fdf)
{
	int	x;
	int	y;
	int	rx;
	int	ry;
	t_point	*p;

	int	fd;
	fd = open("test_maps/test.fdf", O_RDONLY);
	char	*line;
	char	**tab;
	y = 0;
	while (y <= fdf->map_h)
	{
		line = ft_gnl(fd);
		tab = ft_split(line, ' ');
		x = 0;
		while (x <= fdf->map_w)
		{
			printf("%d %d\n", x, y);
			rx = x * fdf->zoom_scale;
			ry = y * fdf->zoom_scale;
			if (x != fdf->map_w)
				f_draw_line(rx, ry, ((x + 1) * fdf->zoom_scale), ry, 0, fdf);
			if (y != fdf->map_h)
				f_draw_line(rx, ry, rx, (y +1) * fdf->zoom_scale, 0, fdf);
			// f_put_pixel(x * fdf->zoom_scale, y * fdf->zoom_scale, 0xFFFFFF, fdf);
			// f_put_pixel((x + 1) * fdf->zoom_scale, y * fdf->zoom_scale, 0xFF0000, fdf);
			x+=1;
		}
		ft_split_free(tab, fdf->map_w);
		free(line);
		y++;
	}	
}