/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:13:44 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/01 08:21:04 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_mlx_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, F_WINDOW_WIDTH,
			F_WINDOW_HEIGHT, F_WINDOW_TITLE);
	fdf->img = mlx_new_image(fdf->mlx, F_WINDOW_WIDTH, F_WINDOW_HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->line_size, &fdf->endian);
}

void
	f_put_pixel(int x, int y, int color, t_fdf *fdf)
{
	char	*dest;

	dest = fdf->addr + (y * fdf->line_size + x * (fdf->bpp / 8));
	*(unsigned int *)dest = color;
}

void
	f_image_clear(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < F_WINDOW_WIDTH)
	{
		j = 0;
		while (j < F_WINDOW_HEIGHT)
		{
			f_put_pixel(i, j, 0xffffff, fdf);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
