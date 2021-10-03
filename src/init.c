/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:38:58 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 12:26:26 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int
	calc_height(char *file, int *fd)
{
	char	*line;
	int		r;
	int		tmp;

	tmp = 0;
	*fd = open(file, O_RDONLY);
	while (1)
	{
		r = ft_gnl(*fd, &line);
		if (line[0] == '\0')
		{
			free(line);
			break ;
		}
		tmp++;
		if (r == 0)
			break ;
	}
	return (tmp);
}

static int
	calc_width(char *file, int *fd)
{
	char	*line;
	char	**s;
	int		i;

	*fd = open(file, O_RDONLY);
	ft_gnl(*fd, &line);
	s = ft_split(line, ' ');
	free(line);
	i = 0;
	while (s[++i])
		;
	ft_split_free(s, i);
	return (i);
}

static void
	parse_map(t_fdf *fdf, char *file, int *fd)
{
	int		x;
	int		y;
	int		r;
	char	*line;
	char	**s;

	y = 0;
	*fd = open(file, O_RDONLY);
	fdf->map_z = malloc(sizeof(int **) * fdf->map_h);
	while (y < fdf->map_h)
	{
		r = ft_gnl(*fd, &line);
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
}

void
	init(t_fdf *fdf, char *file)
{
	int	fd1;
	int	fd2;
	int	fd3;

	fdf->map_h = calc_height(file, &fd1);
	fdf->map_w = calc_width(file, &fd2);
	parse_map(fdf, file, &fd3);
	close(fd1);
	close(fd2);
	close(fd3);
}
