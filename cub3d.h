/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:24:22 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/06 16:43:30 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define TILE_S 12
# define TILE_S3D 50
# define PI 3.14159265359
# define FOV_ANGLE 60
# define WIDTH 2050
# define HEIGHT 1200
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "Libft/libft.h"
# include "MLX/MLX42.h"

typedef struct s_cube
{
	char			**map;
	char			str[4096];
	char			**only_map;
	char			**textures;
	char			**clr;
	int				cnt;
	int				fd;
	char			*no;
	int				maps_start;
	char			*f;
	char			*c;
	char			*so;
	char			*we;
	char			*ea;
	int				*len;	
	mlx_t			*mlx;
	mlx_image_t		*mlx_win;
	float			angle;
	float			ray_angle;
	float			tmpx;
	float			tmpy;
	float			horxstep;
	float			horystep;
	float			vertxstep;
	float			vertystep;
	float			wallheight;
	float			px;
	float			py;
	char			*join;
	float			wallhx;
	float			wallhy;
	float			wallvx;
	float			wallvy;
	int				lr;
	int				hove;
	char			player;
	int				updo;
	int				map_size;
	float			horizhit;
	float			xd;
	float			yd;
	int				*sides;
	float			vertihit;
	float			distance[WIDTH];
	float			x_touch[WIDTH];
	int				fvertihit;
	int				fhorihit;
	float			start;
	int32_t			fl;
	int32_t			cl;
	float			end;
	float			ppl;
}t_cube;

void			*ft_calloc(size_t count, size_t size);
void			ft_free(char **str);
void			open_window(t_cube *maps);
void			wall_check(t_cube *maps);
void			open_window(t_cube *maps);
void			check_color(t_cube *maps);
void			valid_map(t_cube *maps, unsigned int i, unsigned int j);
int				check_nl(char *str);
void			set_null(t_cube *maps);
void			horizantal_intersection(t_cube *maps);
void			horizental_intersection2(t_cube *maps, 
					float nexthorx, float nexthory);
void			vertical_intersection(t_cube *maps);
void			vertical_intersection2(t_cube *maps,
					float nextvertx, float nextverty);
float			distance_b(float xa, float ya, float xb, float yb);
int				hitwall(t_cube *maps, float x, float y);
void			move_player2(t_cube *maps);
void			move_player(void *m);
int				check_walls(t_cube *p);
void			get_player_p(t_cube *maps);
void			draw_map(t_cube *maps);
void			draw_ray(t_cube *maps, int i);	
void			calculs_3d(t_cube *maps, int i, mlx_texture_t **img);
void			draw_map2(t_cube *maps);
void			split_player(t_cube *maps, int couleur);
void			textures_color(t_cube *maps);
unsigned long	get_color(unsigned long r, unsigned long g,
					unsigned long b, int a);
void			set_angle(t_cube *maps);
void			free_img(mlx_texture_t	**img);
void			free_all(t_cube *maps);
int				store_player_side(t_cube *maps);
void			free_dist(t_cube *maps);
void			read_from_file(t_cube *maps, char *file);
int				len_of_2arr(t_cube *maps);
void			read_only_map(t_cube *maps);
int				check_nl(char *s);
void			read_only_textures(t_cube *maps);
int				set_map(t_cube *maps, char **map);
void			get_lines_lenght(t_cube *maps);
void			ft_parsing(char **av, t_cube *maps);
int				check_texter(t_cube *maps);
void			creat_erro(t_cube *maps);
int				check_arr(char *str);
void			angle_set(t_cube *maps);
int				check_double_nl(char *str);
void			floor_ceiling(t_cube *maps);
int				setmaps_w(t_cube *maps, int i, int j);
void			ft_free(char **str);
void			set_null(t_cube *maps);
void			protect_image(t_cube *maps, mlx_texture_t **img);
void			check_image_wh(t_cube *maps, mlx_texture_t **img);
void			fill_map(t_cube *win, int i, int j, int couleur);
void			check_count(t_cube *maps, char **ss);
void			check_coma(char *ss);
int				check_clr(char **str);
int				check_cub(char *str);

#endif