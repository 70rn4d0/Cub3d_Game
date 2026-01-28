/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:15:21 by yabdoul           #+#    #+#             */
/*   Updated: 2025/04/29 13:49:59 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	normalize_vector(t_vecto_2d *vec)
{
	double	length;

	length = sqrt(vec->x * vec->x + vec->y * vec->y);
	if (length > 0)
	{
		vec->x /= length;
		vec->y /= length;
	}
}

t_vecto_2d	get_plane_vector(t_player *player)
{
	t_vecto_2d	v1;

	v1.x = player->directiive_vect.y * 0.66;
	v1.y = -player->directiive_vect.x * 0.66;
	return (v1);
}

void	rotate_vector(t_player **player, char c)
{
	float	x;
	float	y;

	x = (*player)->directiive_vect.x;
	y = (*player)->directiive_vect.y;
	if (c == 'L')
	{
		(*player)->directiive_vect.x = x * cos(-0.01) - y * sin(-0.01);
		(*player)->directiive_vect.y = x * sin(-0.01) + y * cos(-0.01);
	}
	else if (c == 'R')
	{
		(*player)->directiive_vect.x = x * cos(0.01) - y * sin(0.01);
		(*player)->directiive_vect.y = x * sin(0.01) + y * cos(0.01);
	}
	(*player)->plane = get_plane_vector(*player);
}

double	calc_mag(t_vecto_2d v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}
