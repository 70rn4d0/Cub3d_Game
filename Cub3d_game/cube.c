/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:55:53 by yabdoul           #+#    #+#             */
/*   Updated: 2025/05/03 10:16:49 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_linux/mlx.h"
#include "./parsing/head.h"
#include "cub3d.h"
#include <X11/keysym.h>

void	movesetpos(t_game *game, char dir)
{
	move_player(game->map, game->player, dir);
}

int	game_loop(void *param)
{
	t_game	*game;
	t_move	*move;
	char	**map;

	game = (t_game *)param;
	move = (t_move *)game->move;
	map = game->map;
	if (move->move_up == 1)
		movesetpos(game, 'U');
	if (move->move_down == 1)
		movesetpos(game, 'D');
	if (move->rotate_left == 1)
		rotate_vector(&game->player, 'L');
	if (move->rotate_right == 1)
		rotate_vector(&game->player, 'R');
	if (move->move_left == 1)
		movesetpos(game, 'L');
	if (move->move_right == 1)
		movesetpos(game, 'R');
	pre_render_background(game->data, *game->p_data);
	draw_fov_rays(game);
	mlx_put_image_to_window(game->data->mlx_ptr, game->data->win_ptr,
		game->data->img, 0, 0);
}

int	button_x(void *param)
{
	t_game	*game;

	game = (void *)param;
	ft_clean(game);
	exit(0);
}

void	handle_mlx_hooks(t_data *data, t_game *game)
{
	mlx_hook(data->win_ptr, 2, 1L << 0, &keypress_handle, game);
	mlx_hook(data->win_ptr, 3, 1L << 1, &keyrelease_handle, game);
	mlx_hook(data->win_ptr, 17, 0, button_x, game);
}

int	main(int ac, char **av)
{
	t_player		*player;
	t_parsing_data	parsing_data;
	t_game			*game;
	t_data			*data;
	t_move			*move;

	init_parsing_data(&parsing_data);
	parsing_data = parsing_process(ac, av);
	player = malloc(sizeof(t_player));
	set_rgb(&parsing_data);
	game = malloc(sizeof(t_game));
	move = malloc(sizeof(t_move));
	init_movement(move);
	data = render_graphique(parsing_data, player);
	pre_render_background(data, parsing_data);
	init_player(&player, parsing_data.map);
	init_game_struct(game, data, move, player);
	game->map = parsing_data.map;
	game->p_data = &parsing_data;
	init_all_text(game, data);
	draw_fov_rays(game);
	handle_mlx_hooks(data, game);
	mlx_loop_hook(data->mlx_ptr, game_loop, game);
	mlx_loop(data->mlx_ptr);
}
