/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:13:44 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 00:41:08 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_mlx_init(t_fdf *fdf)
{
	fdf->win_w = 1000;
	fdf->win_h = 1000;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_w,
			fdf->win_h, F_WINDOW_TITLE);
	fdf->img = mlx_new_image(fdf->mlx, fdf->win_w, fdf->win_h);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->line_size, &fdf->endian);
}

void
	f_put_pixel(int x, int y, int color, t_fdf *fdf)
{
	char	*dest;

	dest = fdf->addr + (y * fdf->line_size + x * (fdf->bpp / 8));
	if ((x >= 0 && x <= fdf->win_w) && (y >= 0 && y <= fdf->win_h))
		*(unsigned int *)dest = color;
}

void
	f_image_clear(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->win_w)
	{
		j = 0;
		while (j < fdf->win_h)
		{
			f_put_pixel(i, j, 0x010101, fdf);
			j++;
		}
		i++;
	}
}
