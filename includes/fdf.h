/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:08:23 by ljerk             #+#    #+#             */
/*   Updated: 2020/02/20 18:16:14 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>

typedef struct	s_point
{
	float		x;
	float		y;
	int			z;

}				t_point;

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	int			color;
	int			zoom;
	int			shift_x;
	int			shift_y;
	int			projection;
	int			zoom_z;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

void			read_file(char *file, t_fdf *data);
void			draw(t_fdf *data);
void			print_menu(t_fdf *data);
void			set_shifting(int key, t_fdf *data);
void			color_zoom(int key, t_fdf *data);
int				deal_key(int key, t_fdf *data);
void			move_to_center(t_fdf *data);
size_t			ft_countword(char const *s, char c);

#endif
