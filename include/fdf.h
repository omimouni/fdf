/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:27:27 by omimouni          #+#    #+#             */
/*   Updated: 2021/10/03 19:29:41 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define F_WINDOW_TITLE "FdF"
# define ISO_DEG 0.523599

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# ifndef __LINUX__
#  define F_KEY_UP 65362
#  define F_KEY_DOWN 65364
#  define F_KEY_LEFT 65361
#  define F_KEY_RIGHT 65363
#  define F_KEY_W 119
#  define F_KEY_S 115
#  define F_KEY_ESC 65307
#  define F_KEY_C 99
# else
#  define F_KEY_UP 126
#  define F_KEY_DOWN 125
#  define F_KEY_LEFT 123
#  define F_KEY_RIGHT 124
#  define F_KEY_W 13
#  define F_KEY_S 1
#  define F_KEY_ESC 65307
# endif

enum			e_camera {ISO, PARALLEL};

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	int				win_h;
	int				win_w;
	void			*img;
	int				bpp;
	int				line_size;
	int				endian;
	char			*addr;
	int				map_h;
	int				map_w;
	int				**map_z;
	int				**map_color;
	int				zoom_scale;
	int				offset_x;
	int				offset_y;
	int				line_x;
	int				line_y;
	int				line_x_next;
	int				line_y_next;
	double			r_deg;
	int				z_height;
	int				raw_x;
	int				raw_y;
	enum e_camera	camera;
}	t_fdf;

/**
 * MLX utilities
*/
void	f_mlx_init(t_fdf *fdf);
void	f_put_pixel(int x, int y, int color, t_fdf *fdf);
void	f_image_clear(t_fdf *fdf);
void	f_mlx_image(t_fdf *fdf);

/**
 * Parser
 */
void	init(t_fdf *fdf, char *file);
int		parse_hex(char *s);
void	parse_map_z(int x, int y, char *s, t_fdf *fdf);
void	parse_map(t_fdf *fdf, char *file, int *fd);

/**
 * Render
 */

void	f_draw_line(int *p, t_fdf *fdf);
void	f_render(t_fdf *fdf);
int		f_key_hook(int key, t_fdf *fdf);
void	f_color_print(int x, int y, int *p, t_fdf *fdf);

#endif