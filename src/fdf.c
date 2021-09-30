/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:02 by omimouni          #+#    #+#             */
/*   Updated: 2021/09/30 23:14:17 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int
	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		i;
	int		j;
	char	*dest;

	fdf = malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, F_WINDOW_WIDTH,
		F_WINDOW_HEIGHT, F_WINDOW_TITLE);
	fdf->img = mlx_new_image(fdf->mlx, F_WINDOW_WIDTH, F_WINDOW_HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,
		&fdf->line_size, &fdf->endian);
	
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_loop(fdf->mlx);
	return (0);
}
