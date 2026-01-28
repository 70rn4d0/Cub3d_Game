/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:12:06 by yabdoul           #+#    #+#             */
/*   Updated: 2025/04/24 14:13:47 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player **player, char **map)
{
	(*player)->direction = 'W';
	set_player_pos(player, map);
	handle_directive_vect(player);
	(*player)->plane = get_plane_vector(*player);
}

void	set_player_pos(t_player **player, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map)
		exit(1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'S')
			{
				(*player)->pos.x = j + 0.5;
				(*player)->pos.y = i + 0.5;
				(*player)->direction = map[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}

void	handle_directive_vect(t_player **player)
{
	if (((*player)->direction) == 'N')
	{
		(*player)->directiive_vect.x = 0;
		(*player)->directiive_vect.y = 1;
	}
	else if (((*player)->direction) == 'E')
	{
		(*player)->directiive_vect.x = 1;
		(*player)->directiive_vect.y = 0;
	}
	else if (((*player)->direction) == 'W')
	{
		(*player)->directiive_vect.x = -1;
		(*player)->directiive_vect.y = 0;
	}
	else if (((*player)->direction) == 'S')
	{
		(*player)->directiive_vect.x = 0;
		(*player)->directiive_vect.y = -1;
	}
}

int	get_texture_color(t_texture *texture, int x, int y)
{
	int	bytes_per_pixel;
	int	pixel_index;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
	{
		return (0);
	}
	bytes_per_pixel = texture->bpp / 8;
	pixel_index = y * texture->line_length + x * bytes_per_pixel;
	return (*(int *)(texture->addr + pixel_index));
}

void	ft_render_texture(t_data *data, int x, int y, int color)
{
	int	pixel_index;

	pixel_index = (y * data->line_length + x * (data->bits_per_pixel / 8));
	*((unsigned int *)(data->addr + pixel_index)) = color;
}
