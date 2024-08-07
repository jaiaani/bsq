#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *str, int n)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_linelen(char *map)
{
	int	i;
	
	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	return (i);
}

int ft_atoi_basic(char *str) 
{
	int	i;
	int	x;

	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		x = x * 10 + (str[i] - 48);
		i++;
	}
	return (x);
}
