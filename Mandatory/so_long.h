#ifndef SO_LONG_H
# define SO_LONG_H


// typedef struct s_list
// {
// 	int				content;
// 	int				index;
// 	struct s_list	*next;
// }					t_s_list;

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	ft_free2d(char **array);
void 	putstr(char *str);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

void ft_error(char **map, char **tmp_map);
int wall(char *str, int flag, char **ss);
void wall_check(char **ss);
void check_map(char **str);
int	ft_strcmp(char *s1, char *s2);
void check_map(char **str);
void map_name(char *str);
char	**read_map(char **av);
void    flood(char **map, int x, int y);
int *player_p(char **map);
void exit_map(char **map, char **map1);



#endif