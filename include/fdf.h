/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:27 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/02 18:40:14 by omimouni         ###   ########.fr       */
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

#endif