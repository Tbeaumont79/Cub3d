/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:48:42 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/24 14:17:12 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H

# define __CUB3D_H
# define KEY_LEN 8
# define BUFFER_SIZE 32

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef enum		e_value
{
	key_up,
	key_down,
	key_right,
	key_left,
	rot_left,
	rot_right,
	key_escape,
}					t_value;

typedef enum		e_item
{
	item_1,
	item_2,
	item_3,
	item_4,
	item_5,
	item_6
}					t_item;

typedef struct		s_algo
{
	double	floorxwall;
	double	floorywall;
	double	distwall;
	double	distplayer;
	double	currentdist;
	double	weight;
	double	currentfloorx;
	double	currentfloory;
	int		floortexx;
	int		floortexy;
	int		ret;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	wallx;
	double	movespeed;
	double	rotspeed;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	*zbuff;
	int		mapx;
	int		mapy;
	int		**map;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	oldirx;
	double	oldplanex;
	int		x;
	int		texx[4];
	int		texy[4];
	int		tex_num;
	double	texpos;
	double	step;
	double	s_x;
	double	s_y;
	double	invet;
	double	trans_x;
	double	trans_y;
	int		screenx;
	int		s_h;
	int		s_w;
	int		dend_x;
	int		dend_y;
	int		dstart_x;
	int		dstart_y;
	int		sprit_tex_y;
	int		sprit_tex_x;
	int		strip;
	char	*s_name;
	char	*s;
	char	*tmp;
	char	*tmp2;
}					t_algo;

typedef struct		s_game
{
	int				key[KEY_LEN];
	char			spaw_dir;
	int				num_spawn;
	int				**map;
	int				m_space;
	int				m_line;
	int				m_parsed;
	int				wall;
	int				num_sprit;
	int				num_tex;
	unsigned long	flor_color;
	unsigned long	rof_color;
	int				m_h;
	int				m_w;
	int				w_h;
	char			*sprit_tex;
	char			*sprit_tex2;
	int				sprit_light;
	int				check_sprit;
	int				w_w;
}					t_game;

typedef struct		s_tex
{
	void	*tex_img;
	void	*tex;
	char	*name;
	int		endian;
	int		size_line;
	int		bpp;
	int		*datas;
	int		t_h;
	int		t_w;
}					t_tex;

typedef struct		s_hud
{
	int		*datas;
	void	*img;
	int		size_line;
	int		bpp;
	int		endian;
	int		item[6];
}					t_hud;

typedef struct		s_player
{
	int		*data;
	void	*img;
	int 	bpp;
	int		endian;
	int		size_line;
	int		tex_h;
	int		tex_w;
}					t_player;

typedef struct		s_sprit
{
	int		sprite_order;
	int		sprite_distance;
	int		*datas;
	void	*img;
	int		size_line;
	int		bpp;
	int		endian;
	int		h;
	int		w;
	int		posx;
	int		posy;
}					t_sprit;

typedef struct		s_image
{
	void	*ptr;
	void	*win;
	int		*datas;
	void	*img;
	int		endian;
	int		size_line;
	int		bpp;
	int		color;
	int		pixel;
}					t_image;

typedef struct		s_struct
{
	t_image	img;
	t_algo	algo;
	t_game	game;
	t_sprit	*sprit;
	t_tex	tex[5];
	t_hud	hud;
	t_player player;
}					t_struct;

void				draw_sky(t_struct *datas);
void				draw_flor(t_struct *datas);
void				draw(t_struct *datas);
int					keypress(int keyval, void *param);
int					keyparsing(void *param);
int					ft_raycasting(t_struct *datas);
int					map_into_struct(t_struct *datas, char *s);
void				move_up(t_struct *datas);
void				move_down(t_struct *datas);
void				move_right(t_struct *datas);
void				display_whereiam(t_struct *datas);
void				move_left(t_struct *datas);
void				quit(t_struct *datas);
void				init_raycasting_var(t_struct *datas);
void				init_raycasting_var_in_loop(t_struct *datas, int w, int h);
void				render(t_struct *datas);
void				init_img(t_struct *datas);
int					keyunpress(int keyval, void *param);
void				choose_tex(t_struct *datas, int *color, int val);
void				init_algo_tex(t_struct *datas);
int					ft_get_texture(t_struct *datas);
int					ft_error(char *s);
void				ft_puterr(char *err, char *s);
char				*gnl_strjoin(char const *s1, char *s2);
int					get_next_line(int fd, char **line);
int					add_reso(t_struct *datas, char *s);
int					ft_read_file(char *filename, t_struct *datas);
int					add_tex_path(t_struct *datas, char *s, int i);
void				skip_char(char **s, int c);
int					add_sprit_path(t_struct *datas, char *s);
int					ft_get_color(t_struct *datas, char *s);
int					ft_fill_s(t_struct *datas, char *str);
int					ft_check_map(t_struct *datas, char *s);
int					check_all(t_struct *datas);
void				get_sprit_pos(t_struct *datas);
int					sorted_sprite(t_struct *datas);
int					handle_sprit(t_struct *datas);
void				rotate_right(t_struct *datas);
void				rotate_left(t_struct *datas);
void				draw_flor(t_struct *datas);
void				draw_flor_text(t_struct *datas);
void				ft_free(t_struct *datas);
int					exite(int key, void *datas);
int					ft_screenshot(t_struct *datas);
void				w_h_i(int fd, int val);
void				w_i(int fd, int val);
void				w_c(int fd, int color);
void				w_end(int fd, int val);
void				init_raycasting_var(t_struct *datas);
void				init_raycasting_var_in_loop(t_struct *datas, int w, int h);
void				define_sprit_texture(t_struct *datas, int j);
int					define_size(t_struct *datas);
void     			init_player(t_struct *datas);
void    			draw_player(t_struct *datas, int x, int y);
void				draw_hud(t_struct *datas);

#endif
