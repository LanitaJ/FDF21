/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:05:00 by ljerk             #+#    #+#             */
/*   Updated: 2020/02/20 20:38:15 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf *data;

	if (argc != 2)
		ft_putstr("Usage : ./fdf <filename>\n");
	else
	{
		data = (t_fdf*)malloc(sizeof(t_fdf));
		data->z_matrix = NULL;
		read_file(argv[1], data);
		move_to_center(data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
		mlx_hook(data->win_ptr, 2, 0, deal_key, data);
		draw(data);
		mlx_loop(data->mlx_ptr);
	}
}
