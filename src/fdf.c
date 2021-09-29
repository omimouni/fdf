/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:02 by omimouni          #+#    #+#             */
/*   Updated: 2021/09/30 00:09:26 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int
	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*line;
	int		fd;

	fd = open("file", O_RDWR);
	line = ft_gnl(fd);
	free(line);
	line = ft_gnl(fd);
	free(line);
	line = ft_gnl(fd);
	free(line);
	line = ft_gnl(fd);
	free(line);
	line = ft_gnl(fd);
	free(line);

	return (0);
}