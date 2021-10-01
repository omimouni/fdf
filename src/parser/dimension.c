/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:23:32 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/01 20:26:37 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
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
