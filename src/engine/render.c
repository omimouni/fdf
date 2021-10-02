/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:13:31 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/02 15:03:23 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	f_render_points(t_point *p, int nz, t_fdf *fdf)
{
	t_point	*cp;
	t_point	*np;
	int		buff;

	cp = point_create(0, 0, 0);
	np = point_create(0, 0, 0);
	f_iso_project(*p, &(cp->x), &(cp->y));
	buff = p->x;
	p->x += fdf->zoom_scale;
	f_iso_project(*p, &(np->x), &(np->y));
	f_draw_line(cp->x + fdf->offset_x, cp->y + fdf->offset_y,
	 np->x + fdf->offset_x, np->y + fdf->offset_y, 0, fdf);
	p->x = buff;
	p->y += fdf->zoom_scale;
	f_iso_project(*p, &(np->x), &(np->y));
	f_draw_line(cp->x + fdf->offset_x, cp->y + fdf->offset_y
		, np->x + fdf->offset_x, np->y + fdf->offset_y, 0, fdf);
}

void
	f_render(t_fdf *fdf)
{
	int	x;
	int	y;
	t_point	*p;

	x = 0;
	p = point_create(0, 0, 0);
	while (x < fdf->map_h)
	{
		y = 0;
		while (y < fdf->map_w)
		{
			p->x = x * fdf->zoom_scale;
			p->y = y * fdf->zoom_scale;
			p->z = 0;
			f_render_points(p, 0, fdf);
			y++;
		}
		x++;
	}	
}