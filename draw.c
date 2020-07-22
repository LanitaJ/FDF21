/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:33:51 by ljerk             #+#    #+#             */
/*   Updated: 2020/02/19 20:24:10 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static int	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void		isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void		bresenham(t_point s, t_point f, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = f.x - s.x;
	y_step = f.y - s.y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(f.x - s.x) || (int)(f.y - s.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, s.x, s.y, data->color);
		s.x += x_step;
		s.y += y_step;
	}
}

t_point		new_p(int x, int y, t_fdf *data)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = data->z_matrix[y][x];
	p.x *= data->zoom;
	p.y *= data->zoom;
	(data->zoom_z != 0) ? (p.z *= data->zoom_z) : (p.z = 0);
	if (data->projection == 1)
		isometric(&p.x, &p.y, p.z);
	p.x += data->shift_x;
	p.y += data->shift_y;
	return (p);
}

void		draw(t_fdf *data)
{
	t_point	*p;
	float	x;
	float	y;

	p = (t_point*)malloc(sizeof(t_point));
	y = 0;
	print_menu(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(new_p(x, y, data), new_p(x + 1, y, data), data);
			if (y < data->height - 1)
				bresenham(new_p(x, y, data), new_p(x, y + 1, data), data);
			x++;
		}
		y++;
	}
	free(p);
}
