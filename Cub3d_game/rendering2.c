/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:26:30 by yabdoul           #+#    #+#             */
/*   Updated: 2025/04/29 13:11:23 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*render_graphique(t_parsing_data parsing_data, t_player *player)
{
	t_data	*data;
	char	*title;

	title = "CUBE";
	data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 800, title);
	init_player(&player, parsing_data.map);
	handle_directive_vect(&player);
	ft_init_data(data, data->mlx_ptr, 800, 800);
	return (data);
}

t_bg_data	*init_bg_data(t_data *data)
{
	t_bg_data	*bg_data;

	bg_data = malloc(sizeof(t_bg_data));
	if (!bg_data)
		return (NULL);
	ft_init_bg_data(bg_data, data->mlx_ptr, 8000, 800);
	return (bg_data);
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < 800 && y >= 0 && y < 800)
	{
		pxl = data->addr + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)pxl = color;
	}
}
