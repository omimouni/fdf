/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:38:58 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 13:50:17 by omimouni         ###   ########.fr       */
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
		free(line);
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

static int
	parse_hex(char *s)
{
	int		hex;
	int		i;
	char	n;
	int		nchar;

	hex = 0;
	i = 6;
	while (i > 0)
	{
		nchar = '0';
		n = s[i - 1];
		if (n >= 'A' && n <= 'F')
			nchar = 'A' - 10;
		hex += (int)powf(16, 6 - i) * (n - nchar);
		i--;
	}
	return (hex);
}

static void
	parse_map_z(int x, int y, char *s, t_fdf *fdf)
{
	int	i;
	char **d;

	d = ft_split(s, ',');
	i = 0;
	while(d[i])
		i++;
	fdf->map_z[y][x] = atoi(d[0]);
	fdf->map_color[y][x] = -1;
	if (i == 2)
		fdf->map_color[y][x] = parse_hex("FF1099");
	ft_split_free(d, i);
}

static void
	parse_map(t_fdf *fdf, char *file, int *fd)
{
	int		x;
	int		y;
	char	*line;
	char	**s;

	y = 0;
	*fd = open(file, O_RDONLY);
	fdf->map_z = malloc(sizeof(int **) * fdf->map_h);
	fdf->map_color = malloc(sizeof(int **) * fdf->map_h);
	while (y < fdf->map_h)
	{
		ft_gnl(*fd, &line);
		s = ft_split(line, ' ');
		fdf->map_z[y] = malloc(sizeof(int *) * fdf->map_w);
		fdf->map_color[y] = malloc(sizeof(int *) * fdf->map_w);
		free(line);
		x = 0;
		while (x < fdf->map_w)
		{
			parse_map_z(x, y, s[x], fdf);
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
