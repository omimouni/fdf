/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:38:58 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/02 23:49:52 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int
	calc_height(char *file)
{
	char	*line;
	int		r;
	int		fd;
	int		tmp;

	tmp = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		r = ft_gnl(fd, &line);
		if (line[0] == '\0')
		{
			free(line);
			break ;
		}
		tmp++;
		if (r == 0)
			break ;
	}
	// close(fd);
	return (tmp);
}

static int
	calc_width(char *file)
{
	int		fd;
	char	*line;
	char	**s;
	int		i;

	fd = open(file, O_RDONLY);
	ft_gnl(fd, &line);
	s = ft_split(line, ' ');
	free(line);
	i = 0;
	while (s[++i])
		;
	ft_split_free(s, i);
	// close(fd);
	return (i);
}

static void
	parse_map(t_fdf *fdf, char *file)
{
	int		x;
	int		y;
	int		r;
	char	*line;
	char	**s;
	int		fd;

	y = 0;
	fd = open(file, O_RDONLY);
	fdf->map_z = malloc(sizeof(int **) * fdf->map_h);
	while (y < fdf->map_h)
	{
		r = ft_gnl(fd, &line);
		s = ft_split(line, ' ');
		fdf->map_z[y] = malloc(sizeof(int *) * fdf->map_w);
		free(line);
		x = 0;
		while (x < fdf->map_w)
		{
			fdf->map_z[y][x] = atoi(s[x]);
			x++;
		}
		ft_split_free(s, fdf->map_w);
		y++;
	}
	// close(fd);
}

void
	init(t_fdf *fdf, char *file)
{
	fdf->map_h = calc_height(file);
	fdf->map_w = calc_width(file);
	parse_map(fdf, file);
	printf("%d %d\n", fdf->map_w, fdf->map_h);
}
