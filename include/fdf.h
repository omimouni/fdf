/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:27 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 08:56:11 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define F_WINDOW_TITLE "FdF"

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	x_buff;
	int	y_buff;
}	t_point;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		win_h;
	int		win_w;
	void	*img;
	int		bpp;
	int		line_size;
	int		endian;
	char	*addr;
	int		map_h;
	int		map_w;
	int		**map_z;
	int		zoom_scale;
	int		offset_x;
	int		offset_y;

	int		line_x;
	int		line_y;
	int		line_x_next;
	int		line_y_next;

	int		z_height;
}	t_fdf;

/**
 * MLX utilities
*/
void	f_mlx_init(t_fdf *fdf);
void	f_put_pixel(int x, int y, int color, t_fdf *fdf);
void	f_image_clear(t_fdf *fdf);

/**
 * Parser
 */
void	init(t_fdf *fdf, char *file);

/**
 * Render
 */

void	f_draw_line(int x0, int y0, int x1, int y1, int z, t_fdf *fdf);
void	f_render(t_fdf *fdf);
int		f_key_hook(int key, t_fdf *fdf);

#endif