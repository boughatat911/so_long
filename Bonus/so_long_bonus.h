/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:45:33 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/20 18:57:17 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx_linux/mlx.h"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define MAX_ENEMIES 5

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define TILE_SIZE 100

typedef struct s_textures {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit_open;
	void	*enemy;
	void	*exit_close;
	void	*coin[5];
}			t_textures;

typedef struct s_enemy {
	int		x;
	int		y;
}			t_enemy;

typedef struct s_game {
	void		*mlx;
	void		*win;
	char		**map;
	char		**tmp_map;
	char		*num_move;
	char		*str_map;
	char		*s;
	t_textures	textures;
	t_enemy		enemy;
	t_enemy		enemies [MAX_ENEMIES];
	int			num_enemies;
	int			map_width;
	int			map_height;
	int			coin_frame;
	int			x;
	int			y;
	int			fd;
	int			n;
	int			c;
	int			p;
	int			e;
	int			b;
	int			j;
	int			e2x;
	int			e2y;
}				t_game;

///////////////mlx_function//////////////////////////////
void	find_enemies(t_game *g);
int		game_loop(t_game *g);
void	move_enemies(t_game *g);
void	display_move(t_game *g);
void	return_chek(t_game *game);

///////////////mlx_function//////////////////////////////
void	wall_check_2(t_game	*g, int i);
void	free_mlx(t_game *game);
void	mlx_map(t_game	*game);
void	*create_window(t_game *game, int *win_width, int *win_height);
void	load_textures(t_game *game);
void	render_tile(t_game *game, void *texture);
void	render_map(t_game *game, char **map);
int		key_action(int key, void *param);
void	move_player(t_game *g, int new_x, int new_y);
int		action_player(int key, t_game *g);
int		handle_close(t_game *g);
void	exit_status(t_game *game);
void	ins(t_game	*game);

///////////////parsing_function//////////////////////////////
void	check_new_line(char *str, t_game	*game);
char	*ft_itoa(int n, t_game	*game);
void	ft_free2d(char **array);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	putstr(char *str, int fd);
void	ft_map(char	**av, t_game *game);
void	ft_exit(t_game	*game, int fd, char	*str, int mlx);
int		wall(char *str, int flag, t_game *game);
void	wall_check(t_game *g);
int		ft_strcmp(char *s1, char *s2);
void	check_map(t_game *game);
void	map_name(char *str);
void	read_map(char **av, t_game *game);
void	flood(char **map, int y, int x);
void	player_p(t_game	*g);
void	exit_map(t_game *game);

#endif