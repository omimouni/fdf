/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:52:28 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 12:06:32 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#ifndef __LINUX__

# define F_KEY_UP 65362
# define F_KEY_DOWN 65364
# define F_KEY_LEFT 65361
# define F_KEY_RIGHT 65363
# define F_KEY_W 119
# define F_KEY_S 115

#else

# define F_KEY_UP 126
# define F_KEY_DOWN 125
# define F_KEY_LEFT 123
# define F_KEY_RIGHT 124
# define F_KEY_W 13
# define F_KEY_S 1

#endif

static void
	f_render_new_frame(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	f_image_clear(fdf);
	f_render(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

int
	f_key_hook(int key, t_fdf *fdf)
{
	if (key == F_KEY_W)
		fdf->zoom_scale += 4;
	if (key == F_KEY_S)
		fdf->zoom_scale -= 4;
	if (key == F_KEY_UP)
		fdf->offset_y += 10;
	if (key == F_KEY_DOWN)
		fdf->offset_y -= 10;
	if (key == F_KEY_LEFT)
		fdf->offset_x += 10;
	if (key == F_KEY_RIGHT)
		fdf->offset_x -= 10;
	f_render_new_frame(fdf);
}
