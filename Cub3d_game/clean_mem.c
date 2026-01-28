/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:56:12 by yabdoul           #+#    #+#             */
/*   Updated: 2025/05/02 10:39:54 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_double(char **s, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	free_parsing_data(t_parsing_data *data)
{
	free(data->ea);
	free(data->so);
	free(data->we);
	free(data->no);
	free(data->f);
	free(data->c);
}

void	free_textures(t_game *game)
{
	mlx_destroy_image(game->data->mlx_ptr, game->textures_ea->img);
	free(game->textures_ea);
	mlx_destroy_image(game->data->mlx_ptr, game->textures_no->img);
	free(game->textures_no);
	mlx_destroy_image(game->data->mlx_ptr, game->textures_we->img);
	free(game->textures_we);
	mlx_destroy_image(game->data->mlx_ptr, game->textures_so->img);
	free(game->textures_so);
}

void	ft_clean(t_game *game)
{
	free_double(game->map, game->p_data->map_height);
	free(game->player);
	free_textures(game);
	mlx_destroy_image(game->data->mlx_ptr, game->data->img);
	mlx_destroy_window(game->data->mlx_ptr, game->data->win_ptr);
	mlx_destroy_display(game->data->mlx_ptr);
	free(game->data->mlx_ptr);
	free(game->data);
	free(game->move);
	free_parsing_data(game->p_data);
	free(game);
}
