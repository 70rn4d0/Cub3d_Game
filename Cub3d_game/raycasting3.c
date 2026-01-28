/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:07:25 by yabdoul           #+#    #+#             */
/*   Updated: 2025/04/24 14:07:47 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_step(double val)
{
	if (val < 0)
		return (-1);
	return (1);
}

double	get_delta(double val)
{
	if (val != 0)
		return (fabs(1.0 / val));
	return (1e30);
}

void	cast_single_ray(t_game *game, int i)
{
	double		camera_x;
	t_vecto_2d	ray;
	t_vecto_2d	delta;
	t_vecto_2d	step;

	camera_x = 2.0 * ((double)i / 800.0) - 1.0;
	ray.x = game->player->directiive_vect.x + game->player->plane.x * camera_x;
	ray.y = game->player->directiive_vect.y + game->player->plane.y * camera_x;
	delta.x = get_delta(ray.x);
	delta.y = get_delta(ray.y);
	step.x = get_step(ray.x);
	step.y = get_step(ray.y);
	handle_ray_loop(game, ray, step, i);
}

void	textures_loop(t_helper helper, t_game *game, t_drawer drawer,
		t_vecto_2d ray)
{
	t_texture	*textures;

	textures = choose_text_side(game, drawer, ray);
	while (helper.y < drawer.end)
	{
		helper.tex_y = (int)helper.tex_pos;
		if (helper.tex_y < 0)
			helper.tex_y = 0;
		if (helper.tex_y >= textures->height)
			helper.tex_y = textures->height - 1;
		helper.text_x = (int)helper.text_x;
		if (helper.text_x < 0)
			helper.text_x = 0;
		if (helper.text_x >= textures->width)
			helper.text_x = textures->width - 1;
		helper.tex_pos += helper.step_tex;
		helper.color = get_texture_color(textures, helper.text_x, helper.tex_y);
		ft_render_texture(game->data, drawer.col, helper.y, helper.color);
		helper.y++;
	}
}

void	draw_fov_rays(t_game *game)
{
	int	i;

	i = 0;
	while (i < 800)
	{
		cast_single_ray(game, i);
		i++;
	}
}
