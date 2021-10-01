/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:02 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/01 20:56:27 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int
	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	f_parse_dimension(fdf, argv[1]);
	f_mlx_init(fdf);
	f_image_clear(fdf);

	f_draw_line(10, 0, 10, 20, fdf);

	// Draw points
	int	x;
	int	y;
	int	xn;
	int	yn;
	int	i;
	int	j;

	x = 0;
	i = 0;
	while (i < fdf->map_w)
	{
		j = 0;
		y = 0;
		xn = x;
		while (j < fdf->map_h)
		{
			j++;
			yn = y;
			y+=10;
			// f_draw_line(xn, yn, x, y, fdf);
		}
		x += 10;
		i++;
	}

	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_loop(fdf->mlx);
	free(fdf);
	return (0);
}
