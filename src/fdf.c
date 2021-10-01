/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:02 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/01 13:23:57 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void
	f_parse_dimension(t_fdf *fdf, char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	**tab;

	fdf->map_h = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = ft_gnl(fd);
		if (!line)
			break ;
		else
		{
			fdf->map_h++;
			free(line);
		}
	}
	close(fd);
	fdf->map_w = 0;
	fd = open(file, O_RDONLY);
	line = ft_gnl(fd);
	tab = ft_split(line, ' ');
	i = 0;
	while (tab[i++])
		fdf->map_w++;
	close(fd);
	free(line);
	ft_split_free(tab, fdf->map_w);
}

void
	draw_line(int y, int x, char *z, t_fdf *fdf, int y1, int x1)
{
	int	i;
	int	iso_x;
	int	iso_x_next;
	int	iso_y_next;
	int	iso_y;

	i = atoi(z);
	iso_x = (x - y) * cos(0.523599);
	iso_y = -i + (x + y) * sin(0.523599);
	
	if (i != 0)
		f_put_pixel(iso_x + 300 ,iso_y + 200, 0xFF0000, fdf);
	else
		f_put_pixel(iso_x + 300 , iso_y + 200, 0xFFFFFF, fdf);

	int	dx;
	int	dy;
	int	Dd;
	int	yy;
	int	xx;

	iso_x_next = (xx - yy) * cos(0.523599);
	iso_y_next = -i + (xx + yy) * sin(0.523599);

	dx = iso_x_next - iso_x;
	dy = iso_y_next - iso_y;

	Dd =  2 * dy - dx;
	yy = y;
	xx = x;
	while (xx < x1)
	{

		f_put_pixel(iso_x_next + 300, iso_y_next + 300, 0xFFFFFF, fdf);
		if (Dd > 0)
		{
			yy = yy + 1;
			Dd = Dd - 2*dx;
		}
		Dd = Dd + 2*dy; 
		xx++;
	}
	
}
void
	*draw_frame(char *file, t_fdf *fdf)
{
	int	fd;
	char	*line;
	char	**tokens;
	int		x;
	int		y;
	int		i;
	int		x1;
	int		y1;

	fd = open(file, O_RDONLY);
	x = 0;
	x1 = 0;
	y1 = 0;
	while (1)
	{
		line = ft_gnl(fd);
		if (!line)
			break ;
		else
		{
			y = 0;
			tokens = ft_split(line, ' ');
			i = 0;
			x+=15;
			while (i < fdf->map_w)
			{
				y+=15;
				draw_line(x, y, tokens[i], fdf, x1, y1);
				y1 = y;
				i++;
			}
			x1 = x;
			free(line);
		}
	}
	close(fd);
}

int
	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	f_parse_dimension(fdf, argv[1]);
	f_mlx_init(fdf);
	f_image_clear(fdf);
	draw_frame(argv[1], fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_loop(fdf->mlx);
	free(fdf);
	return (0);
}
