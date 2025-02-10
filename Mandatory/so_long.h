#ifndef SO_LONG_H
# define SO_LONG_H

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
	void	*exit;
} t_textures;

typedef struct s_game {
	void		*mlx;
	void		*win;
	char		**map;
	char		**tmp_map;
	t_textures	textures;
	int		x;
	int		y;
	int		n;
	int		c;
	// int 	map_width;
	// int 	map_height;
}	t_game;

# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx_linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#define TILE_SIZE 100



///////////////mlx_function//////////////////////////////
void	mlx_map(t_game	*game);
void	*create_window(t_game *game, int *win_width, int *win_height);
void	load_textures(t_game *game);
void	render_tile(t_game *game, void *texture);
void	render_map(t_game *game, char **map);
int		key_action(int key,void *param);
int		handle_keypress(int key, t_game *g); //************* */


///////////////parsing_function//////////////////////////////
void	ft_free2d(char **array);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void 	putstr(char *str, int fd);
void 	ft_map(char	**av,t_game *game);
void 	ft_error(char **map, char **tmp_map);
int 	wall(char *str, int flag, char **ss);
void	wall_check(t_game *game);
// void	check_map(char **str);
int		ft_strcmp(char *s1, char *s2);
void	check_map(t_game *game);
void	map_name(char *str);
void	read_map(char **av, t_game *game);
void	   flood(char **map, int y, int x);
void	player_p(char **map, int *y, int *x);
void	exit_map(char **map, char **map1);



#endif