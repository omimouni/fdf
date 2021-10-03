/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:52:28 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 09:03:16 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# define F_KEY_UP 126
# define F_KEY_DOWN 125
# define F_KEY_LEFT 123
# define F_KEY_RIGHT 124
# define F_KEY_W 13
# define F_KEY_S 1

static void
	f_render_new_frame(t_fdf *fdf)
{
	f_image_clear(fdf);
	f_render(fdf);
	mlx_put_image_to_window(fdf->win, fdf->win, fdf->img, 0, 0);
}

int
	f_key_hook(int key, t_fdf *fdf)
{

	if (key == F_KEY_W)
		fdf->zoom_scale += 2;
	if (key == F_KEY_S)
		fdf->zoom_scale -= 2;
	if (key == F_KEY_UP)
		fdf->offset_y += 10;
	if (key == F_KEY_DOWN)
		fdf->offset_y -= 10;
	if (key == F_KEY_LEFT)
		fdf->offset_x -= 10;
	if (key == F_KEY_RIGHT)
		fdf->offset_x += 10;
	f_render_new_frame(fdf);

}