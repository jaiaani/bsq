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

int	ft_is_printable(char c)
{
    return (c >= 32 && c <= 126);
}

int ft_atoi_basic(char *str) {
    int i = 0;
    int x = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        x = x * 10 + (str[i] - '0');
        i++;
    }
    return x;
}
