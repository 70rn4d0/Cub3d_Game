/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:45:19 by yabdoul           #+#    #+#             */
/*   Updated: 2025/04/29 14:27:05 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vecto_2d	init_side_dist(t_player *player, t_vecto_2d ray, t_vecto_2d delta)
{
	t_vecto_2d	side;

	if (ray.x < 0)
		side.x = (player->pos.x - floor(player->pos.x) + 0.001) * delta.x;
	else
		side.x = (floor(player->pos.x) + 1.0 - player->pos.x + 0.001) * delta.x;
	if (ray.y < 0)
		side.y = (player->pos.y - floor(player->pos.y) + 0.001) * delta.y;
	else
		side.y = (floor(player->pos.y) + 1.0 - player->pos.y + 0.001) * delta.y;
	return (side);
}

void	draw_textured_column(t_game *game, t_vecto_2d ray, t_drawer drawer,
		double dist)
{
	t_helper	helper;
	t_texture	*textures;

	textures = choose_text_side(game, drawer, ray);
	if (drawer.side_check == 0)
		helper.wall_hit = game->player->pos.y + dist * ray.y;
	else
		helper.wall_hit = game->player->pos.x + dist * ray.x;
	helper.wall_hit -= floor(helper.wall_hit);
	helper.text_x = helper.wall_hit * textures->width;
	if ((drawer.side_check == 0 && ray.x > 0) || (drawer.side_check == 1
			&& ray.y < 0))
		helper.text_x = textures->width - helper.text_x - 1;
	helper.step_tex = 1.0 * textures->height / drawer.height;
	helper.tex_pos = (drawer.start - 400 + drawer.height / 2) * helper.step_tex;
	helper.y = drawer.start;
	textures_loop(helper, game, drawer, ray);
}

void	draw_wall_slice(t_game *game, t_vecto_2d ray, t_vecto_2d side,
		t_drawer drawer)
{
	double	dist;

	if (drawer.side_check == 0)
		dist = side.x - drawer.delta.x;
	else
		dist = side.y - drawer.delta.y;
	if (dist < 0.01)
		dist = 0.01;
	drawer.height = (int)(800 / dist);
	drawer.start = 400 - (drawer.height / 2);
	if (drawer.start < 0)
		drawer.start = 0;
	drawer.end = 400 + (drawer.height / 2);
	if (drawer.end >= 800)
		drawer.end = 799;
	draw_textured_column(game, ray, drawer, dist);
}

t_texture	*choose_text_side(t_game *game, t_drawer drawer, t_vecto_2d ray)
{
	if (drawer.side_check == 0)
	{
		if (ray.x > 0)
			return (game->textures_we);
		else
			return (game->textures_ea);
	}
	else
	{
		if (ray.y > 0)
			return (game->textures_no);
		else
			return (game->textures_so);
	}
}

t_vecto_2d	init_delta(t_vecto_2d ray)
{
	t_vecto_2d	delta;

	delta.x = get_delta(ray.x);
	delta.y = get_delta(ray.y);
	return (delta);
}
