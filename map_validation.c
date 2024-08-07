
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *map);
int	ft_linelen(char *map);
int ft_atoi_basic(char *str);
char    *ft_strndup(char *str, int n);

int	map_check_first_line(char *map) //FIX
{
	int	fl_l;
	int	i;

	i = 0;
	while (i < 3)
	{
		if (map[i] < 32 && map[i] > 127)
			return (0);
		if (map[i] == map[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	map_check_chars(char *map, char *map_info, int fl_l)
{
	char	empty;
	char	obstacle;
	char	full;
	int	i;

	empty = map_info[fl_l - 2];
	obstacle = map_info[fl_l - 1];
	full = map_info[fl_l];
	i = 0;
	while (map[i])
	{
		if (map[i] != empty && map[i] != obstacle && map[i] != full && map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}


int	map_check_lineslen(char *map)
{
	int	i;
	int	fl_l;
	int	map_size;
	
	fl_l = ft_linelen(map);
	map_size = ft_strlen(map);
	i = 0;
	while (i < map_size - 2)
	{
		if (map[i] == '\n')
		{
			if (ft_linelen(&map[i + 1]) != fl_l)
				return (0); 
		}
		i++;
	}
	return (1);
}

int	map_check_breaklines(char *map, int num_l)
{
	int	i;
	int	bl;
	int linelen;
	int	bl_qnty;
	
	i = 0;
	bl_qnty = 0;
	linelen = ft_linelen(map);
	bl = linelen;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			bl_qnty++;
		i++;
	}
	if (bl_qnty !=  num_l)
			return (0);
	i = 0;
	while (i <= num_l)
	{
		if (map[bl] != '\n')
		{
			return (0);
			linelen = linelen + 1;
			bl = bl + linelen;
		}
		i++;
	}
	return (1);
}

int	map_is_valid(char *map, char *map_info)
{
	int	fs_ll;
	int	num_l;
	char	*map_rows_str;
	int	map_rows_qty;
	
	fs_ll = ft_linelen(map);
	map_rows_str = ft_strndup(map, fs_ll - 3);
	map_rows_qty = ft_atoi_basic(map_rows_str);
	fs_ll =  fs_ll + 1;
	if (!map_check_first_line(map))
			return (0);
	if (!map_check_chars(map + fs_ll, map_info, fs_ll))
			return (0);
	if (!map_check_lineslen(map + fs_ll))
			return (0);
	if (!map_check_breaklines(map + fs_ll, num_l))
			return(0);
	free(map_rows_str);
	return (1);
}
