/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:45:33 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/17 15:56:50 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>  ///**************/// 
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx_linux/mlx.h"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_textures {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit_open;
}			t_textures;

typedef struct s_game {
	void		*mlx;
	void		*win;
	char		**map;
	char		**tmp_map;
	char		*s;
	t_textures	textures;
	int			x;
	int			y;
	int			fd;
	int			n;
	int			c;
	int			p;
	int			e;
	int			j;
}				t_game;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define TILE_SIZE 100

///////////////mlx_function//////////////////////////////
void	mlx_map(t_game	*game);
void	*create_window(t_game *game, int *win_width, int *win_height);
void	load_textures(t_game *game);
void	render_tile(t_game *game, void *texture);
void	render_map(t_game *game, char **map);
int		key_action(int key, void *param);
int		handle_keypress(int key, t_game *g); //************* */
void	move_player(t_game *g, int new_x, int new_y);
void	action_player(int key, t_game *g);
int		handle_keypress(int key, t_game *g);
int		handle_close(t_game *g);

///////////////parsing_function//////////////////////////////
void	ft_itoa(int n);
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
// void	check_map(char **str);
int		ft_strcmp(char *s1, char *s2);
void	check_map(t_game *game);
void	map_name(char *str);
void	read_map(char **av, t_game *game);
void	flood(char **map, int y, int x);
void	player_p(t_game	*g);
void	exit_map(t_game *game);

#endif