/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:22:46 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/01 21:26:24 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_draw_line(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
	int	m;
	int	x;
	int	y;

	if ((x1 - x0) == 0)
		m = y1 - y0;
	else
		m = (y1 - y0)/(x1 - x0);
	x = x0;
	while (x < x1)
	{
		y = m*x;
		x++;
		f_put_pixel(x, y, 0xFFFFFF, fdf);	
	}
}