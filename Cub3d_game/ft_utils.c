/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:42:50 by yabdoul           #+#    #+#             */
/*   Updated: 2025/05/03 12:58:41 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line/get_next_line.h"

t_vecto_2d	check_dir(char **map, t_player *player, char direction)
{
	t_vecto_2d	newpos;
	double		speed;

	speed = 0.05;
	if (direction == 'U')
		newpos = add_vecto(player->pos, scale_vecto(player->directiive_vect,
					speed));
	else if (direction == 'D')
		newpos = sub_vecto(player->pos, scale_vecto(player->directiive_vect,
					speed));
	else if (direction == 'L')
		newpos = sub_vecto(player->pos, scale_vecto(player->plane, speed));
	else if (direction == 'R')
		newpos = add_vecto(player->pos, scale_vecto(player->plane, speed));
	return (newpos);
}

int	is_surrounded_by_walls(char **map, int y, int x)
{
	if (y <= 0 || x <= 0 || map[y + 1] == NULL || map[y][x + 1] == '\0')
		return (1);
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1' && map[y][x - 1] == '1'
		&& map[y][x + 1] == '1')
		return (1);
	return (0);
}

void	move_player(char **map, t_player *player, char direction)
{
	t_vecto_2d	newpos;
	int			next_x;
	int			next_y;

	player->plane = get_plane_vector(player);
	normalize_vector(&player->directiive_vect);
	newpos = check_dir(map, player, direction);
	next_x = (int)(newpos.x);
	next_y = (int)(newpos.y);
	if (next_x < 0 || next_y < 0 || map[next_y] == NULL
		|| map[next_y][next_x] == '\0')
		return ;
	if (map[next_y][next_x] == '1')
		return ;
	if (is_surrounded_by_walls(map, next_y, next_x))
		return ;
	player->pos = newpos;
}

void	init_movement(t_move *move)
{
	move->move_down = 0;
	move->move_up = 0;
	move->move_left = 0;
	move->move_right = 0;
	move->rotate_left = 0;
	move->rotate_right = 0;
}

unsigned int	rgb_to_hexa(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
