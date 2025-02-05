#ifndef SO_LONG_H
# define SO_LONG_H


// typedef struct s_list
// {
// 	int				content;
// 	int				index;
// 	struct s_list	*next;
// }					t_s_list;

#include <stdio.h> ///////////////////
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include "../mlx_linux/mlx.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#define TILE_SIZE 100

void mlx_map(char **map);
void	ft_free2d(char **array);
// void 	putstr(char *str);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void putstr(char *str, int fd);
void ft_map(char	**av);
void ft_error(char **map, char **tmp_map);
int wall(char *str, int flag, char **ss);
void wall_check(char **ss);
void check_map(char **str);
int	ft_strcmp(char *s1, char *s2);
void check_map(char **str);
void map_name(char *str);
char	**read_map(char **av, char **map);
void    flood(char **map, int x, int y);
void player_p(char **map, int *x, int *y);
void exit_map(char **map, char **map1);



#endif