/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:27 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/01 08:38:22 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define F_WINDOW_HEIGHT 800
# define F_WINDOW_WIDTH 800
# define F_WINDOW_TITLE "FdF"

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		line_size;
	int		endian;
	char	*addr;
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