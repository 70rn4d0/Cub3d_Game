/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:58:43 by yabdoul           #+#    #+#             */
/*   Updated: 2025/05/03 12:57:15 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keypress_handle(int keycode, void *param)
{
	t_game	*game;
	t_move	*move;

	game = (t_game *)param;
	move = game->move;
	if (keycode == 65307)
	{
		ft_clean(game);
		exit(0);
	}
	else if (keycode == 119 && move->move_up == 0)
		move->move_up = 1;
	else if (keycode == 115 && move->move_down == 0)
		move->move_down = 1;
	else if (keycode == 100 && move->move_right == 0)
		move->move_right = 1;
	else if (keycode == 97 && move->move_left == 0)
		move->move_left = 1;
	else if (keycode == 65363 && move->rotate_left == 0)
		move->rotate_left = 1;
	else if (keycode == 65361 && move->rotate_right == 0)
		move->rotate_right = 1;
	return (0);
}

int	keyrelease_handle(int keycode, void *param)
{
	t_game	*game;
	t_move	*move;

	game = (t_game *)param;
	move = game->move;
	if (keycode == 119 && move->move_up == 1)
		move->move_up = 0;
	else if (keycode == 115 && move->move_down == 1)
		move->move_down = 0;
	else if (keycode == 100 && move->move_right == 1)
		move->move_right = 0;
	else if (keycode == 97 && move->move_left == 1)
		move->move_left = 0;
	else if (keycode == 65363 && move->rotate_left == 1)
		move->rotate_left = 0;
	else if (keycode == 65361 && move->rotate_right == 1)
		move->rotate_right = 0;
	return (1);
}
