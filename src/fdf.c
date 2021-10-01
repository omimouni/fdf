/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:02 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/01 08:20:30 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int
	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		i;
	int		j;
	char	*dest;

	fdf = malloc(sizeof(t_fdf));
	f_mlx_init(fdf);
	f_image_clear(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
