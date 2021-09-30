/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:29 by omimouni          #+#    #+#             */
/*   Updated: 2021/09/30 23:07:12 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_put_pixel(int x, int y, int color, t_fdf *fdf)
{
	char	*dest;

	dest = fdf->addr + (y * fdf->line_size + x * (fdf->bpp / 8));
	*(unsigned int *)dest = color; 
}
