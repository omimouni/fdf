/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:02 by omimouni          #+#    #+#             */
/*   Updated: 2021/09/28 18:41:20 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int
	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 300, 300, "FdF");
	mlx_loop(fdf->mlx);
	return (0);
}