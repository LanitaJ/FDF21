/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:10:15 by ljerk             #+#    #+#             */
/*   Updated: 2020/02/20 20:45:12 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include <errno.h>

static int		get_height(char *file)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line) == 1)
	{
		height++;
		free(line);
	}
	close(fd);
	if (height == 0)
	{
		perror("Incorrect MAP");
		exit(1);
	}
	return (height);
}

static int		get_width(char *file)
{
	int			fd;
	char		*line;
	size_t		width;
	size_t		height;

	width = 0;
	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_countword(line, ' ');
	free(line);
	height = get_height(file) - 1;
	while (height--)
	{
		get_next_line(fd, &line);
		if (width != ft_countword(line, ' '))
		{
			free(line);
			close(fd);
			return (0);
		}
		width = ft_countword(line, ' ');
		free(line);
	}
	close(fd);
	return (width);
}

static void		fill_matrix(int *res, char *line)
{
	char	**num;
	int		i;

	i = 0;
	num = ft_strsplit(line, ' ');
	while (num[i])
	{
		if (ft_atoi(num[i]) == 0 && *num[i] != '0')
		{
			ft_putstr("Invalid map\n");
			exit(0);
		}
		res[i] = ft_atoi(num[i]);
		free(num[i]);
		i++;
	}
	free(num);
}

static int		check(char *file, t_fdf *data)
{
	int	fd;

	if (!((fd = open(file, O_RDONLY)) >= 0))
	{
		if (errno == 0)
			ft_putendl_fd("Incorrect MAP", 2);
		else
			perror("Incorrect MAP");
		exit(1);
	}
	data->height = get_height(file);
	data->width = get_width(file);
	if (!data->height || !data->width)
	{
		if (data->height == 0)
			ft_putstr("Found wrong height.\n");
		if (data->width == 0)
			ft_putstr("Found wrong length.\n");
		return (0);
	}
	return (1);
}

void			read_file(char *file, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	if (check(file, data))
	{
		data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1));
		i = 0;
		while (i <= data->height)
			data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width));
		fd = open(file, O_RDONLY, 0);
		i = 0;
		while (get_next_line(fd, &line))
		{
			fill_matrix(data->z_matrix[i++], line);
			free(line);
		}
		close(fd);
	}
	else if (!(data->z_matrix))
	{
		ft_putstr("Invalid map\n");
		exit(0);
	}
}
