/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:13:09 by yabdoul           #+#    #+#             */
/*   Updated: 2025/05/03 10:38:21 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./minilibx_linux/mlx.h"
# include "./parsing/head.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# define FOV 60
# define SPEED 1
# define R_SPEED 1
# define X_EVENT_KEY_PRESS 
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_MOUSE_PRESS 4
# define X_EVENT_MOUSE_RELEASE 5
# define X_EVENT_MOUSE_MOVE 6
# define X_EVENT_EXIT 17

typedef struct s_helper
{
	double					wall_hit;
	double					step_tex;
	double					tex_pos;
	int						y;
	int						text_x;
	int						tex_y;
	int						color;
	int						side;
	double					dist;
}							t_helper;
typedef struct s_move
{
	int						move_up;
	int						move_down;
	int						move_left;
	int						move_right;
	int						rotate_left;
	int						rotate_right;
}							t_move;
typedef struct s_data
{
	void					*addr;
	int						line_length;
	int						bits_per_pixel;
	void					*img;
	void					*mlx_ptr;
	void					*win_ptr;
	int						endian;
}							t_data;
typedef struct s_uv
{
	double					u;
	double					v;
}							t_uv;
typedef struct s_vecto_2d
{
	double					x;
	double					y;

}							t_vecto_2d;
typedef struct s_drawer
{
	int						col;
	int						start;
	int						end;
	int						height;
	int						side_check;
	struct s_vecto_2d		delta;
	int						color;
}							t_drawer;

typedef struct s_player
{
	char					direction;
	t_vecto_2d				pos;
	t_vecto_2d				directiive_vect;
	t_vecto_2d				plane;
}							t_player;
typedef struct s_bg_data
{
	void					*addr;
	int						line_length;
	int						bits_per_pixel;
	void					*img;
	void					*mlx_ptr;
	void					*win_ptr;
	int						endian;
}							t_bg_data;
typedef struct s_texture
{
	void					*img;
	char					*addr;
	int						width;
	int						height;
	int						bpp;
	int						line_length;
	int						endian;
}							t_texture;

typedef struct s_game
{
	struct s_data			*data;
	struct s_texture		*textures_no;
	struct s_texture		*textures_we;
	struct s_texture		*textures_ea;
	struct s_texture		*textures_so;
	struct s_parsing_data	*p_data;
	//    struct s_bg_data *bg_data ;
	struct s_player			*player;
	struct s_move			*move;
	char					**map;
}							t_game;

void						init_game(void);
int							ft_strcmp(char *s1, char *s2);
t_vecto_2d					init_side_dist(t_player *player, t_vecto_2d ray,
								t_vecto_2d delta);
void						draw_wall_slice(t_game *game, t_vecto_2d ray,
								t_vecto_2d side, t_drawer drawer);
void						textures_loop(t_helper helper, t_game *game,
								t_drawer drawer, t_vecto_2d ray);
t_vecto_2d					init_delta(t_vecto_2d ray);
void						move_player(char **map, t_player *player,
								char direction);
void						init_game_struct(t_game *game, t_data *data,
								t_move *move, t_player *player);
char						**parse_map(void);
void						init_player(t_player **player, char **map);
int							get_texture_color(t_texture *texture, int x, int y);
void						draw_direction(t_player *player, t_data *data,
								char **map);
t_vecto_2d					get_plane_vector(t_player *player);
t_vecto_2d					init_vecto(double x, double y);
t_vecto_2d					add_vecto(t_vecto_2d v1, t_vecto_2d v2);
t_vecto_2d					scale_vecto(t_vecto_2d v1, double s_factor);
void						ft_render_texture(t_data *data, int x, int y,
								int color);
t_vecto_2d					sub_vecto(t_vecto_2d v1, t_vecto_2d v2);
void						set_player_pos(t_player **player, char **map);
void						ft_put_pixel(t_data *data, int x, int y, int color);
void						ft_clean(t_game *game);
void						handle_directive_vect(t_player **player);
void						draw_sky(t_data *data, int start_wall);
void						set_rgb(t_parsing_data *data);
void						handle_ray_loop(t_game *game, t_vecto_2d ray,
								t_vecto_2d step, int col);
int							get_step(double val);
unsigned int				rgb_to_hexa(int r, int g, int b);
int							keyrelease_handle(int keycode, void *param);
int							keypress_handle(int keycode, void *param);
void						update_x(double *side_x, int *map_x, double delta_x,
								int *side_check);
void						update_y(double *side_y, int *map_y, double delta_y,
								int *side_check);
double						get_delta(double val);
void						draw_floor(t_data *data, int end_wall);
void						rotate_player_left(t_player *player, t_data *data);
void						rotate_vector(t_player **player, char c);
void						normalize_vector(t_vecto_2d *v);
t_uv						**store_uv_texture(t_texture *textu);
void						draw_fov_rays(t_game *game);
double						get_ray_hit_x(t_player *player, double ray_dist);
double						get_text_x(double hit_x, double wall_start_x,
								t_texture *texture, double wall_end_x);
t_data						*render_graphique(t_parsing_data parsing_data,
								t_player *player);
t_texture					*setuptextures(t_data *data,
								t_parsing_data parsing_data);
t_bg_data					*init_bg_data(t_data *data);
void						pre_render_background(t_data *data,
								t_parsing_data parsing_data);
t_texture					*init_textures(t_data *data, char *path);
void						control_movement(t_data *data);
t_move						create_move(void);
t_texture					*choose_text_side(t_game *game, t_drawer drawer,
								t_vecto_2d ray);
void						init_all_text(t_game *game, t_data *data);
void						init_movement(t_move *move);
void						ft_init_bg_data(t_bg_data *data, void *mlx,
								int width, int height);
void						ft_init_data(t_data *data, void *mlx, int width,
								int height);
#endif