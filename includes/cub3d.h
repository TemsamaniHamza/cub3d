/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okachkac <okachkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:31:05 by okachkac          #+#    #+#             */
/*   Updated: 2025/02/26 14:46:50 by okachkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SCREEN_W 1920
# define SCREEN_H 1080
# define FOV 1.0472
# define MOVE_SPEED 0.2
# define ROT_SPEED 0.07
# define TEXTURE_WIDTH 512
# define TEXTURE_HEIGHT 512
# define BUFFER_SIZE 46464
# define PADDING 0.06

enum
{
	TEX_NORTH,
	TEX_SOUTH,
	TEX_EAST,
	TEX_WEST,
	NUM_TEXTURES
};

typedef struct s_line_params
{
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			x1;
	int			y1;
}				t_line_params;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_texture;

typedef struct s_ray_params
{
	double		dir_x;
	double		dir_y;
	double		dist;
	int			side;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_dist;
	double		raw_dist;
}				t_ray_params;

typedef struct s_wall_data
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		tex_pos;
	double		step;
	int			tex_x;
}				t_wall_data;

typedef struct s_parsed
{
	int			celling;
	int			floor;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		**file;
	char		**map_copy;
	int			flg_no;
	int			flg_so;
	int			flg_ea;
	int			flg_we;
	int			flg_celling;
	int			flg_floor;
	int			nbr_player;
}				t_parsed;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	double		px;
	double		py;
	double		p_angle;
	double		ray_dir_x;
	char		**maps;
	char		*tex_paths[NUM_TEXTURES];
	double		ray_dir_y;
	t_parsed	h;
	t_texture	textures[NUM_TEXTURES];
}				t_data;

int				close_window(t_data *data);
int				key_press(int keycode, t_data *data);
void			raycast(t_data *d);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				is_valid_position(t_data *d, double x, double y);
void			load_textures(t_data *d);
int				render_frame(t_data *data);
void			init_ray_params(t_ray_params *rp, t_data *d, double ray_angle);
void			perform_dda(t_data *d, t_ray_params *rp);
void			calculate_wall_dis(t_ray_params *rp, t_data *d,
					double ray_angle);
void			draw_wall_column(t_data *d, int x, t_ray_params *rp);
t_wall_data		prepare_wall_data(t_data *d, t_ray_params *rp, t_texture *tex);
t_texture		*get_wall_texture(t_data *d, t_ray_params *rp);
void			draw_wall_column(t_data *d, int x, t_ray_params *rp);
void			init_map(t_data *data, int i, int j);
void			init_ray_steps(t_ray_params *rp, t_data *d);
void			init_ray_direction(t_ray_params *rp, t_data *d,
					double ray_angle);
int				is_valid_position(t_data *d, double x, double y);
void			handle_rotation(int keycode, t_data *d);
double			get_move_direction(int key, double player_angle);
int				handle_movement(int key, t_data *d);
int				key_press(int keycode, t_data *d);
/******************atoi*************HAMZA FUNCTIONS *******************/

char			*get_next_line(int fd);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
t_data			ft_parse(char *str);
void			ft_printf(char *str);
void			ft_free_printf(t_data *ret, char *msg);

char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin_gnl(char *s1, char *s2);
char			*ft_strchr_gnl(char *s, int c);
size_t			ft_strlen_gnl(const char *s);
char			*ft_check_new_line(int fd, char *reminder);
char			*ft_clean_line(char *reminder);
char			*ft_set_reminder(char *reminder);
void			ft_parse_file(t_data *ret, char *str);
bool			ft_isspace_new(char c);
int				ft_check_walls(char **line, int i, int flag, t_data *ret);
int				ft_atoi_rgbx(char *nptr);
int				ft_overflow_2(char *nptr, int i);
int				ft_overflow_3(char *nptr, int i);
int				ft_overflow(char *nptr);
void			ft_init_flag(t_data *ret);
char			*ft_strchr(char *s, int c);
size_t			ft_strlen(const char *s);
void			free_double_array(char **str);
t_data			*copy_of_file(t_data *ret, char *str);
t_data			*ft_strtrim_array(t_data *ret);
t_data			*ft_set_check_info(t_data *ret);
void			ft_is_map_valid(t_data *ret);
int				ft_find_first_m(t_data *ret, int i);
int				how_many_lines_left(t_data *ret, int j);
char			**ft_cpy_map(t_data *ret, int k, int j);
int				ft_check_bellow_map_walls(char **map_cpy, t_data *ret);
t_data			*ft_set_info_two(t_data *ret, int i);
t_data			*ft_set_info(t_data *ret, int i);
char			*ft_decimal_to_hex(int str);
int				ft_hex_to_decimal(char *str);
int				ft_checkdecimal(unsigned int n);
char			*ft_strrev(char *str);
bool			ft_check_flag(t_data *ret);
void			ft_free_printf_3(t_data *ret);
void			ft_free_printf_2(t_data *ret);
bool			ft_line_valid(char *map, int j);
void			free_double_printf(char **line, t_data *ret, char *msg);
void			check_west_texture(t_data *ret);
void			ft_check_info_extension(t_data *ret);
char			**ft_handle_color2(t_data *ret, int i);
char			*ft_handle_color3(char **ss, char *temp);
char			*ft_decimal_to_hex2(int str, char *ret, char *hex);
void			ft_free_printf_succ(t_data *ret);
void			ft_handle_color4(t_data *ret, char *str);
void			ft_init_textures(t_data *ret);

#endif