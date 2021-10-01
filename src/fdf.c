/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:02 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/01 12:04:11 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void
	draw_image(t_fdf *fdf, char *file)
{
	int	offsetx = 0;
	int	offsety = 0;
	int	x;
	int	y;
	int iso_x;
	int iso_y;
	char	*line;
	int		fd;
	char	**s;
	int	i;
	// y = 0;
	// while (y < fdf->map_w)
	// {
	// 	x = 0;
	// 	while (x < fdf->map_h)
	// 	{
	// 		if ((x % 20 == 0 || y % 20 == 0)
	// 		 || (x == fdf->map_w - 1 || y == fdf->map_h - 1))
	// 		{
	// 			iso_x = (x - y) * cos(0.523599);
	// 			iso_y = (x + y) * sin(0.523599);
	// 			iso_x = iso_x + offsetx;
	// 			iso_y = iso_y + offsety;
	// 			f_put_pixel(iso_x, iso_y, 0xFFFFFF, fdf);
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }

	fd = open("test_maps/10-2.fdf", O_RDONLY);
	x = 0;
	while((line = ft_gnl(fd)))
	{
		// TODO: trim the string
		// TODO: errors trigger
		s = ft_split(line, ' ');
		i = 0;
		y = 0;
		while (s[i])
		{
			iso_x = y ;
			iso_y = x ;
			iso_x = (iso_x - iso_y) * cos(0.523599);
			iso_y = (atoi(s[i])) + (iso_x + iso_y) * sin(0.523599);
			iso_x = iso_x + offsetx;
			iso_y = iso_y + offsety;
			f_put_pixel(iso_x, iso_y, 0xFFFFFF, fdf);
			y+=10;
			i++;
		}
		ft_split_free(s, i);
		free(line);
		x += 10;
	}
}

int
	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		i;
	int		j;
	char	*dest;

	fdf = malloc(sizeof(t_fdf));
	fdf->map_w = 500;
	fdf->map_h = 500;
	// f_parser(fdf, "");
	f_mlx_init(fdf);
	f_image_clear(fdf);
	
	// Draw an image 
	draw_image(fdf, "test_map/42.fdf");

	mlx_loop(fdf->mlx);
	free(fdf);
	return (0);
}
