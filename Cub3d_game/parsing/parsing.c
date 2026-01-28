/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:36:41 by aech-chi          #+#    #+#             */
/*   Updated: 2025/05/03 10:36:07 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_free(t_parsing_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->f)
		free(data->f);
	if (data->c)
		free(data->c);
	if (data->map)
	{
		i = 0;
		while (data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	init_parsing_data(data);
}

int	parse_check(char **av, t_parsing_data *data)
{
	if (file_extension(av[1], 0))
		return (1);
	if (file_permission(av[1]))
		return (1);
	if (read_file(av[1], data, -1))
		return (1);
	if (check_map(data))
		return (1);
	if (texture_permission(data))
		return (1);
	if (hexa_color(data))
		return (1);
	return (0);
}

void	init_parsing_data(t_parsing_data *data)
{
	data->no = NULL;
	data->ea = NULL;
	data->so = NULL;
	data->we = NULL;
	data->r_f = 0;
	data->g_f = 0;
	data->b_f = 0;
	data->r_c = 0;
	data->g_c = 0;
	data->b_c = 0;
	data->map = NULL;
	data->player_dir = '\0';
	data->map_height = 0;
	data->map_width = 0;
	data->f = NULL;
	data->c = NULL;
}

t_parsing_data	parsing_process(int ac, char **av)
{
	t_parsing_data	data;

	if (ac != 2)
	{
		printf("Error: Wrong argument count\n");
		exit(3);
	}
	init_parsing_data(&data);
	if (parse_check(av, &data))
	{
		ft_free(&data);
		write(1, "error ❌\n", 11);
		exit(2);
	}
	return (data);
}
