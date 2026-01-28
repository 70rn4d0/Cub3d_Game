/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:07:45 by yabdoul           #+#    #+#             */
/*   Updated: 2025/04/27 16:47:02 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_linux/mlx.h"
#include "./parsing/head.h"
#include "cub3d.h"
#include <stdio.h>

void	ft_init_data(t_data *data, void *mlx, int width, int height)
{
	data->img = mlx_new_image(mlx, width, height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->mlx_ptr = mlx;
}

void	ft_init_bg_data(t_bg_data *data, void *mlx, int width, int height)
{
	data->img = mlx_new_image(mlx, width, height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->mlx_ptr = mlx;
}

void	ft_draw_sky(t_data *data, int sky_color)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < 400)
	{
		x = 0;
		while (x < 800)
		{
			ft_put_pixel(data, x, y, sky_color);
			x++;
		}
		y++;
	}
}

void	ft_draw_floor(t_data *data, int floor_color)
{
	int	y;
	int	x;

	y = 400;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			ft_put_pixel(data, x, y, floor_color);
			x++;
		}
		y++;
	}
}

void	pre_render_background(t_data *data, t_parsing_data parsing_data)
{
	ft_draw_sky(data, rgb_to_hexa(parsing_data.r_c, parsing_data.g_c,
			parsing_data.b_c));
	ft_draw_floor(data, rgb_to_hexa(parsing_data.r_f, parsing_data.g_f,
			parsing_data.b_f));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
