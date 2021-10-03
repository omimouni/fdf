/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 12:27:09 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 14:01:35 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_color_print(int x, int y, int *p, t_fdf *fdf)
{
	int	color;

	if (fdf->map_color[fdf->raw_y][fdf->raw_x] == -1)
		color = 0xffffff;
	else
		color = fdf->map_color[fdf->raw_y][fdf->raw_x];
	f_put_pixel(x, y, color, fdf);
}
