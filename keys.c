/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:21:54 by ljerk             #+#    #+#             */
/*   Updated: 2020/02/20 21:02:49 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	print_menu(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xffffff, "How to \
																	use");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 45, 0xffffff, "Zoom: \
																	+/-");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 70, 0xffffff, "Move: \
																	Arrows");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 95, 0xffffff, "Change \
																	color: \
																	0 - 9");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 120, 0xffffff, "Flatten: \
																		z/x");
}

void	set_shifting(int key, t_fdf *data)
{
	if (key == 126 && data->shift_y > -200)
		data->shift_y -= 10;
	if (key == 125 && data->shift_y < 700)
		data->shift_y += 10;
	if (key == 123 && data->shift_x > -200)
		data->shift_x -= 10;
	if (key == 124 && data->shift_x < 700)
		data->shift_x += 10;
}

void	color_zoom(int key, t_fdf *data)
{
	if (key == 18)
		data->color = 0xFF0000;
	if (key == 19)
		data->color = 0xFF8C00;
	if (key == 20)
		data->color = 0xFFD700;
	if (key == 21)
		data->color = 0x008000;
	if (key == 23)
		data->color = 0x40E0D0;
	if (key == 22)
		data->color = 0x0000FF;
	if (key == 26)
		data->color = 0xDC143C;
	if (key == 28)
		data->color = 0xFFF5EE;
	if (key == 25)
		data->color = 0x6495ED;
	if (key == 29)
		data->color = 0xFF00C1;
	if (key == 24 && data->zoom < 50)
		data->zoom++;
	if ((key == 27) && data->zoom > 7)
		data->zoom--;
}

int		deal_key(int key, t_fdf *data)
{
	if (key >= 123 && key <= 126)
		set_shifting(key, data);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
		exit(0);
	}
	if (key >= 18 && key <= 29)
		color_zoom(key, data);
	if (key == 34)
		data->projection = 1;
	if (key == 35)
		data->projection = 0;
	if (key == 6 && data->zoom_z < 40)
		data->zoom_z++;
	if (key == 7 && data->zoom_z > -40)
		data->zoom_z--;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

void	move_to_center(t_fdf *data)
{
	data->shift_x = 500;
	data->shift_y = 400;
	data->zoom = 20;
	data->color = 0xFF00C1;
	data->zoom_z = 2;
}
