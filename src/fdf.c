/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:02 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/04 12:51:10 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void
	f_z_factor(t_fdf *fdf)
{
	int		**tmp;
	int		i;
	int		j;

	tmp = fdf->map_z;
	i = 0;
	while (i < fdf->map_h)
	{
		j = 0;
		while (j < fdf->map_w)
		{
			tmp[i][j] = fdf->map_z[i][j] * fdf->z_height;
			j++;
		}
		i++;
	}	
}

int
	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		fdf = malloc(sizeof(t_fdf));
		fdf->max_z = 0;
		init(fdf, argv[1]);
		fdf->camera = ISO;
		f_responsive(fdf);
		f_z_factor(fdf);
		f_mlx_init(fdf);
		f_image_clear(fdf);
		f_render(fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
		mlx_key_hook(fdf->win, f_key_hook, fdf);
		mlx_loop(fdf->mlx);
		free(fdf);
	}
	return (0);
}
