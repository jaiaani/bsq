
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *map);
int	ft_linelen(char *map);
int ft_atoi_basic(char *str);
char    *ft_strndup(char *str, int n);
int	ft_is_printable(char c);

int	map_check_first_line(char *map, char *map_info)
{
   	int	fl_l;
	char    empty;
        char    obstacle;
        char    full;
	
	fl_l = ft_linelen(map);
	if (fl_l < 4) 
    	    return (0);
   	empty = map_info[fl_l - 3];
        obstacle = map_info[fl_l - 2];
        full = map_info[fl_l - 1];
   	 if (!ft_is_printable(full) || !ft_is_printable(obstacle) || !ft_is_printable(empty)) 
		 return 0;
   	 if (full == obstacle || full == empty || obstacle == empty)
		 return 0;
	 return 1;
}

int	map_check_chars(char *map, char *map_info, int fl_l)
{
	char	empty;
	char	obstacle;
	char	full;
	int	i;

	empty = map_info[fl_l - 3];
	obstacle = map_info[fl_l - 2];
	full = map_info[fl_l - 1];
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

int	map_check_breaklinees(char *map, int num_l)
{
	int	i;
	int	bl;
	int	linelen;
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
			return (0);

		linelen = linelen + 1;
		bl = bl + linelen;
		i++;
	}
	return (1);
}

int	map_check_breaklines(char *map, int num_l)
{
    int i = 0;
    int bl_qnty = 0;
    int linelen = ft_linelen(map);
    
    while (map[i] != '\0') {
        if (map[i] == '\n') {
            bl_qnty++;
        }
        i++;
    }
    if (bl_qnty != num_l) {
        return 0;
    }

    i = 0;
    while (i < num_l) 
    {
        int line_end = i * (linelen + 1) + linelen;
        if (map[line_end] != '\n') {
            return 0;
        }
        i++;
    }
    return 1;
}

int	map_is_valid(char *map, char *map_info)
{
	int	fs_ll;
	int	num_l;
	char	*map_rows_str;
	int	map_rows_qty;
	
	fs_ll = ft_linelen(map);
	printf("%d", fs_ll);
	map_rows_str = ft_strndup(map, 2);
	printf("%s", map_rows_str);
	map_rows_qty = ft_atoi_basic(map_rows_str);
	if (!map_check_first_line(map, map_info))
			return (0);
	if (!map_check_chars(map + fs_ll, map_info, fs_ll))
			return (0);
	if (!map_check_lineslen(map + fs_ll + 1))
			return (0);
	if (!map_check_breaklines(map + fs_ll + 1, map_rows_qty))
			return(0);
	free(map_rows_str);
	return (1);
}
