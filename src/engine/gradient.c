/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 12:27:09 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 18:04:47 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_color_print(int x, int y, int *p, t_fdf *fdf)
{
	int	color;

	if (p[6] == -1)
		color = p[7];
	else
		color = p[6];
	if (p[6] == -1 && p[7] == -1)
		color = 0xffffff;
	f_put_pixel(x, y, color, fdf);
}
