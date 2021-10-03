/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 12:27:09 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 12:29:31 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_color_print(int x, int y, int *p, t_fdf *fdf)
{
	if (p[5] || p[4])
		f_put_pixel(x, y, 0xffff00, fdf);
	else
		f_put_pixel(x, y, 0xffffff, fdf);
}
