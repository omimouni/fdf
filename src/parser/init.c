/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:38:58 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/04 18:26:10 by omimouni         ###   ########.fr       */
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

static void
	f_eject(int err)
{
	if (err != 0)
	{
		perror("Invalid File");
		exit(-1);
	}
}

static void
	f_check_error(int *fd, int size)
{
	int		err;
	int		r;
	char	*line;
	char	**tab;

	err = 0;
	while (1)
	{
		r = ft_gnl(*fd, &line);
		if (r == 0)
		{
			free(line);
			break ;
		}
		tab = ft_split(line, ' ');
		free(line);
		r = 0;
		while (tab[r])
			r++;
		ft_split_free(tab, r);
		if (r != size)
			err = -1;
	}
	f_eject(err);
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
	f_check_error(fd, i);
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
