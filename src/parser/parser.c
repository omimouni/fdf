/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:07:48 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/01 10:38:13 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_p
	*f_map_p_create(int x, int y, char *z)
{
	t_map_p	*tmp;

	tmp = malloc(sizeof(t_map_p));
	tmp->x = (x);
	tmp->y = (y);
	tmp->weight = atoi(z);
	return (tmp);
}

void
	f_parser(t_fdf *fdf, char *map_file)
{
	int	fd;
	char	*line;
	char	**s;
	int		i;
	int		x;
	int		y;

	
	// Calculate map_w
	fd = open("test_maps/42.fdf", O_RDONLY);
	line = ft_gnl(fd);
	s = ft_split(line, ' ');
	fdf->map_w = 0;
	while (s[fdf->map_w])
		fdf->map_w++;
	ft_split_free(s, fdf->map_w);
	free(line);
	close(fd);

	// Calculate map_h
	fd = open("test_maps/42.fdf", O_RDONLY);
	fdf->map_h = 0;
	while ((line = ft_gnl(fd)))
	{
		fdf->map_h++;
		free(line);
	}
	printf("-> %d %d\n", fdf->map_h, fdf->map_w);
	close(fd);

	// Parsing the map
	// TODO: Handle erros
	fdf->map_p = malloc(sizeof(t_map_p **) * fdf->map_w);
	fd = open("test_maps/42.fdf", O_RDONLY);
	x = 0;
	while((line = ft_gnl(fd)))
	{
		// TODO: trim the string
		// TODO: errors trigger
		s = ft_split(line, ' ');
		i = 0;
		y = 0;
		fdf->map_p[x] = malloc(sizeof(t_map_p *) * fdf->map_h);
		while (s[i])
		{
			fdf->map_p[x] = f_map_p_create(x, y, s[i]);
			y++;
			i++;
		}
		ft_split_free(s, i);
		free(line);
		x++;
	}
}
