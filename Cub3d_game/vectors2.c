/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:16:10 by yabdoul           #+#    #+#             */
/*   Updated: 2025/04/24 14:18:04 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vecto_2d	init_vecto(double x, double y)
{
	t_vecto_2d	vecto;

	vecto.x = x;
	vecto.y = y;
	return (vecto);
}

t_vecto_2d	add_vecto(t_vecto_2d v1, t_vecto_2d v2)
{
	t_vecto_2d	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return (result);
}

t_vecto_2d	sub_vecto(t_vecto_2d v1, t_vecto_2d v2)
{
	t_vecto_2d	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	return (result);
}

t_vecto_2d	scale_vecto(t_vecto_2d v1, double s_factor)
{
	t_vecto_2d	result;

	result.x = v1.x * s_factor;
	result.y = v1.y * s_factor;
	return (result);
}
