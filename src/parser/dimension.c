/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:23:32 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/02 17:01:53 by omimouni         ###   ########.fr       */
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
	int		re;
	fdf->map_h = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		re = ft_gnl(fd, &line);
		fdf->map_h++;
		free(line);
		if (re == 0)
			break ;
	}
	close(fd);
	fdf->map_w = 0;
	fd = open(file, O_RDONLY);
	ft_gnl(fd, &line);
	tab = ft_split(line, ' ');
	i = 0;
	while (tab[i++])
		fdf->map_w++;
	close(fd);
	free(line);
	ft_split_free(tab, fdf->map_w);
}
