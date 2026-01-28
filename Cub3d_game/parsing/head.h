/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:39:46 by aech-chi          #+#    #+#             */
/*   Updated: 2025/05/03 10:36:15 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "../get_next_line/get_next_line.h"
# include <ctype.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_parsing_data
{
	char	*no;
	char	*ea;
	char	*so;
	char	*we;
	char	**map;
	char	player_dir;
	char	*f;
	char	*c;
	int		r_f;
	int		g_f;
	int		b_f;
	int		r_c;
	int		g_c;
	int		b_c;
	int		map_height;
	int		map_width;
}	t_parsing_data;

t_parsing_data	parsing_process(int ac, char **av);
int				parse_check(char **av, t_parsing_data *data);
void			init_parsing_data(t_parsing_data *data);
int				file_extension(char *av, bool c);
int				file_permission(char *map);
int				open_file(char *map, int fd);
int				texture_permission(t_parsing_data *data);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(const char *nptr);
char			*ft_strrchr( char *s, int c);
int				read_file(char *filename, t_parsing_data *data, int fd);
int				is_spaces_only(char *line);
int				is_empty_line(char *line);
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				check_map(t_parsing_data *data);
void			free_2d_array(char **arr);
int				open_file(char *map, int fd);
int				texture_permission(t_parsing_data *data);
int				hexa_color(t_parsing_data *data);
int				valid_rgb( char *rgb_str);
int				is_valid_number(const char *str);
char			*ft_strtok(char *str, const char *delim);
int				check_player_count(t_parsing_data *data);
void			set_rgb(t_parsing_data *data);
int				store_raw_map_line(char *line, t_parsing_data *data);
int				process_config_line(char *line, t_parsing_data *data);
int				count_fasila(char *rgb_str);

#endif
