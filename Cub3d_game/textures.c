/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:02:15 by yabdoul           #+#    #+#             */
/*   Updated: 2025/04/24 18:03:12 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*init_textures(t_data *data, char *path)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	texture->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &texture->width,
			&texture->height);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_length, &texture->endian);
	return (texture);
}

void	init_all_text(t_game *game, t_data *data)
{
	game->textures_ea = init_textures(data, game->p_data->ea);
	game->textures_no = init_textures(data, game->p_data->no);
	game->textures_we = init_textures(data, game->p_data->we);
	game->textures_so = init_textures(data, game->p_data->so);
}

double	get_ray_hit_x(t_player *player, double ray_dist)
{
	return (player->pos.x + ray_dist * player->directiive_vect.x);
}

double	get_text_x(double hit_x, double wall_start_x, t_texture *texture,
		double wall_end_x)
{
	return (((hit_x - wall_start_x) / (wall_end_x - wall_start_x))
		* texture->width);
}
