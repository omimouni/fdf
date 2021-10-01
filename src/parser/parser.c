/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:07:48 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/01 09:18:35 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_parser(t_fdf *fdf, char *map_file)
{
	int	fd;
	char	*line;
	char	**s;
	int		i;
	int		x;
	int		y;

	fd = open("test_maps/42.fdf", O_RDONLY);

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
			printf("%d %d -> %s\n",x, y, s[i]);
			y++;
			i++;
		}
		x++;
	}	
}
