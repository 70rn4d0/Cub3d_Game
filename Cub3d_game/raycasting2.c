/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:45:48 by yabdoul           #+#    #+#             */
/*   Updated: 2025/04/30 15:12:56 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_map_cordi(int *map_x, int *map_y, t_game *game)
{
	*map_x = (int)game->player->pos.x;
	*map_y = (int)game->player->pos.y;
}

void	check_for_hit(int map_x, int map_y, t_game *game, int *hit)
{
	if (game->map[map_y][map_x] == '1')
		*hit = 1;
}

void	set_drawer(t_drawer *drawer, int col, t_vecto_2d delta)
{
	drawer->col = col;
	drawer->delta = delta;
}

void	set_side_pos(t_vecto_2d *side, int *map, t_drawer *drawer,
		t_vecto_2d step)
{
	if (side->x < side->y)
	{
		*map += step.x;
		side->x += drawer->delta.x;
		drawer->side_check = 0;
	}
	else
	{
		*map += step.y;
		side->y += drawer->delta.y;
		drawer->side_check = 1;
	}
}

void	handle_ray_loop(t_game *game, t_vecto_2d ray, t_vecto_2d step, int col)
{
	t_vecto_2d	side;
	t_drawer	drawer;
	int			map_x;
	int			map_y;
	int			hit;

	set_drawer(&drawer, col, init_delta(ray));
	side = init_side_dist(game->player, ray, drawer.delta);
	set_map_cordi(&map_x, &map_y, game);
	hit = 0;
	while (!hit)
	{
		if (side.x < side.y)
			set_side_pos(&side, &map_x, &drawer, step);
		else
			set_side_pos(&side, &map_y, &drawer, step);
		check_for_hit(map_x, map_y, game, &hit);
	}
	draw_wall_slice(game, ray, side, drawer);
}
