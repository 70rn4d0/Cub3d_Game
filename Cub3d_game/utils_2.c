/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:03:27 by yabdoul           #+#    #+#             */
/*   Updated: 2025/04/29 13:11:36 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game_struct(t_game *game, t_data *data, t_move *move,
		t_player *player)
{
	game->data = data;
	game->player = player;
	game->move = move;
}

void	update_x(double *side_x, int *map_x, double delta_x, int *side_check)
{
	*side_x += delta_x;
	*map_x += 1;
	*side_check = 0;
}

void	update_y(double *side_y, int *map_y, double delta_y, int *side_check)
{
	*side_y += delta_y;
	*map_y += 1;
	*side_check = 1;
}
