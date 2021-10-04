/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responsive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:53:12 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/04 12:34:13 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_responsive(t_fdf *fdf)
{
	if (fdf->map_w <= 50)
		fdf->zoom_scale = 40;
	else if (fdf->map_w <= 200)
		fdf->zoom_scale = 20;
	else
		fdf->zoom_scale = 10;
	fdf->win_w = fdf->map_w * fdf->zoom_scale + 200;
	fdf->win_h = fdf->map_h * fdf->zoom_scale + 200;
	if (fdf->win_h > 1000 || fdf->win_w > 1000)
	{
		fdf->win_h = 1000;
		fdf->win_w = 1000;
	}
	fdf->offset_x = fdf->win_w / 4;
	fdf->offset_y = fdf->win_h / 4;
	fdf->z_height = 1;
}
