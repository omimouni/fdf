/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:38:58 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 20:03:53 by omimouni         ###   ########.fr       */
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
	if (*fd < 0)
	{
		perror("Error: ");
		exit(-1);
	}
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
