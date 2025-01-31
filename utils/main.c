#include "../libc/libc.h"

void putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
		write(1, "\n", 1);
}
int wall(char *str, int flag)
{
	int i = ft_strlen(str) - 1;
	if (flag == 1)
	{
		if (str[i] != '1' || str[0] != '1')
			return (911);
	}
	else if (flag == 2)
		{
			i = 0;
			while (str[i])
			{
				if(str[i] != '1')
					(printf("error_1_wall\n"),exit(1));
				i++;
			}
		}
	return (0);
}
void wall_check(char **ss)
{
	int i = 0;
	int c = 0;
	int p = 0;
	int e = 0;
	int j = 0;
	char *str;
	while (ss[j])
	{
		str = ss[j];
		i = 0;
    while (str[i])
    {
        if(!((str[i] == '1') || (str[i] == '0') || (str[i] == 'C') || (str[i] == 'P') || (str[i] == 'E')))
			printf("error_wall\n"),exit(1);
		if(str[i] == 'C')
			c++;
		else if(str[i] == 'P')
			p++;
		else if(str[i] == 'E')
			e++;
        i++;
    }
		j++;
	}
	printf("%d\n", p);
	if(p > 1 || e == 0 || c == 0)
		(printf("error_<\n"), exit(1));
	// j -= 1;
	wall(ss[j-1], 2);	
	wall(ss[0], 2);	
}

void check_map(char *str, t_list	**a)
{
	char **str2 = ft_split(str, '\n');
	int i = 0;
	while (str2[i])
	{
		ft_lstadd_back(a, ft_lstnew(ft_strdup(str2[i])));
		i++;
	}
	wall_check(str2);
	t_list *tmp = *a;
	while (tmp)
	{
		t_list *b = *a;
		while (b)
		{
			if(((ft_strlen(b->content) != ft_strlen(tmp->content))) || wall(b->content, 1) == 911)
			{
				printf("Error_map_len\n");
				exit(1);
			}
			b = b->next;
		}
		tmp = tmp->next;
	}
}

#include <string.h> //dw 
void map_name(char *str)
{
	int i;

	if (ft_strlen(str) < 4 || strcmp(".ber", &str[ft_strlen(str) - 4]))
		printf("Error_map_name\n");

	// i = ft_strlen(str) - 1;
	// if(str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b' && str[i - 3] == '.')
	// 	return ;
	exit(1);
}

int main(int ac, char **av)
{
	t_list *a;
	t_list *tmp;
	a = NULL;
	if (ac != 2)
		return(printf("error_ac\n"), 2);
	map_name(av[1]);
    char *line;
    int fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	if(!line)
		return(printf("error_empty\n"), 2);
	char *str = NULL;
	while (line)
    {
		str = ft_strjoin(str, line);
		line = get_next_line(fd);
	}
	int  i = ft_strlen(str) - 1;
	if (str[i] == '\n')
		return(printf("error_empty\n"), 2);
	i = 0;
	while (str[i])
	{
		if((str[i] == '\n' &&  str[i + 1] == '\n') || str[0] == '\n')
			(printf("Error_\\n\n"), exit(1));
		i++;
	}
	
	check_map(str, &a);
	tmp = a;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
    return 0;
}

