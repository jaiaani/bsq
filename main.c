

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	BUF_SIZE 1024

int	map_is_valid(char *map, char *map_info);
int	ft_atoi_basic(char c);
int	ft_linelen(char *map);
char	*ft_strndup(char *str, int n);
int	max_sub_matrix(char **matrix_map, int rows, int cols);
char	**convert_to_matrix(char *map, int *rows, int *cols);

int	map_catch(char *file, char *dest)
{
	int	file_d;
	
	file_d = open(file, O_RDONLY);
	if(file_d == -1)
	{
		printf("Error\n");
		return (-1);
	}
	ssize_t n_read = read(file_d, dest, BUF_SIZE - 1);
	while (n_read > 0)
	{
		dest[n_read] = '\0';
		n_read = read(file_d, dest, BUF_SIZE - 1);
	}
	return (0);
}

char	*ft_map_info(char *map)
{
	int	i;
	int	fl_l;
	char		*map_info;
	
	fl_l = ft_linelen(map);
	i = 3;
	map_info = (char *)malloc(sizeof(char) * (4));
	if(map_info == NULL)
		return (NULL);
	while(i >= 0)
	{
		map_info[i] = map[i];
		i--;
	}
	map_info[i] = '\0';
	return (map_info);
}

int	map_rows_qty(char *map, int fs_linelen)
{
	char	*map_rows;
	int	rows;

	map_rows = ft_strndup(map, fs_linelen - 3);
	rows = atoi(map_rows);
	return (rows);
}

int	main(int argc, char *argv[])
{
	char	map[BUF_SIZE];
	char	*map_info;
	int	rows;
	int	cols;
	char	**matrix_map;

	map_catch(argv[1], map);
	map_info = ft_map_info(map);
	if(map_is_valid(map, map_info))
	{
		printf("valid");
		matrix_map = convert_to_matrix(map + 5, &rows, &cols);
		max_sub_matrix(matrix_map, rows, cols);
    		free(matrix_map);


	}
	return (0);
}
