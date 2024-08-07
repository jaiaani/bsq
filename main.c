/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:24:06 by jados-sa          #+#    #+#             */
/*   Updated: 2024/08/06 22:28:21 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define	BUF_SIZE 1024

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

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

char	*ft_map_chars(char *map)
{
	int	i;
	char		*map_chars;
	
	i = 0;
	map_chars = (char *)malloc(sizeof(char) * (4));
	if(map_chars == NULL)
		return (NULL);
	while(i <= 3)
	{
		map_chars[i] = map[i];
		i++;
	}
	map_chars[i] = '\0';
	return (map_chars);
}

int	ft_linelen(char *map)
{
	int	i;
	
	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	return (i);
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

int	map_check_breaklines(char *map, int num_l, int len_l)
{
	int	i;
	int	bl;
	
	i = 0;
	bl = len_l;
	printf("%d"
	while (i <= num_l)
	{
		if(map[bl] != '\n')
			printf(":%c: = %d\n", map[bl], bl);
		len_l = len_l + 1;
		bl = bl + len_l;
		i++;
	}
	return (1);
}

int	teste(char *map)
{
	int	i;
	i = 0;
	while(map[i] != '\n')
		i++;
	printf("%c = %d", map[47], i);
	return 0;
}

int	main(int argc, char *argv[])
{
	char	map[BUF_SIZE];
	char	*map_chars;
	int	ft_linel;


	map_catch(argv[1], map);
	ft_linel = ft_linelen(map + 5);
	//printf("%d", ft_linel);
	//map_chars = ft_map_chars(map);
	//printf("the length of lines are valid?: %d", map_check_lineslen(map + 5));
	printf("the lines end with break line?: %d", map_check_breaklines(map + 5, 8, ft_linel));
	//printf("%d", ft_strlen(map));
	//printf("%s\n", map_chars);
	//printf("%s", map);
	//teste(map + 5);
	return (0);
}
