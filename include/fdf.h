/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:27 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/01 11:26:00 by omimouni         ###   ########.fr       */
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

typedef struct s_map_p
{
	int		x;
	int		y;
	int		weight;
}	t_map_p;

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
	t_map_p	**map_p;
}	t_fdf;

/**
 * MLX utilities
*/
void
	f_mlx_init(t_fdf *fdf);
void
	f_put_pixel(int x, int y, int color, t_fdf *fdf);
void
	f_image_clear(t_fdf *fdf);

/**
 * 
 */
void
	f_parser(t_fdf *fdf, char *map_file);

#endif