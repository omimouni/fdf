/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:02 by omimouni          #+#    #+#             */
/*   Updated: 2021/09/29 23:33:54 by omimouni         ###   ########.fr       */
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
	line = ft_gnl(fd);
	line = ft_gnl(fd);
	return (0);
}