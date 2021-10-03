/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:52:28 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 20:48:42 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void
	f_render_new_frame(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	f_image_clear(fdf);
	f_render(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

static void
	f_exit(t_fdf *fdf)
{
	int	i;

	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	i = 0;
	while (i < fdf->map_h)
		free(fdf->map_z[i++]);
	free(fdf->map_z);
	exit(0);
}

void
	f_scale_key(int key, t_fdf *fdf)
{
	if (key == F_KEY_W)
		fdf->zoom_scale += 1;
	if (key == F_KEY_S)
		fdf->zoom_scale -= 1;
	if (fdf->zoom_scale <= 0)
		fdf->zoom_scale = 1;
}

int
	f_key_hook(int key, t_fdf *fdf)
{
	if (IS_BONUS)
	{
		f_scale_key(key, fdf);
		if (key == F_KEY_UP)
			fdf->offset_y += 10 * fdf->zoom_scale;
		if (key == F_KEY_DOWN)
			fdf->offset_y -= 10 * fdf->zoom_scale;
		if (key == F_KEY_LEFT)
			fdf->offset_x += 10 * fdf->zoom_scale;
		if (key == F_KEY_RIGHT)
			fdf->offset_x -= 10 * fdf->zoom_scale;
		if (key == F_KEY_C)
		{
			if (fdf->camera == ISO)
				fdf->camera = PARALLEL;
			else
				fdf->camera = ISO;
		}
		f_render_new_frame(fdf);
	}
	if (key == F_KEY_ESC)
		f_exit(fdf);
	return (0);
}
