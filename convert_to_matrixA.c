#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != c))
		s++;
	if (*s == c)
		return ((char *)s);
	return ((char*)NULL);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i + 1] = src[i];
	return (dest);
}

char	*ft_strtok(char *str, char sepa)
{
	static char	*stock = NULL;
	char		*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	if (str != NULL)
		stock = ft_strdup(str);
	while (*stock != '\0')
	{
		if (i == 0 && *stock != sepa)
		{
			i = 1;
			ptr = stock;
		}
		else if (i == 1 && *stock == sepa)
		{
			*stock = '\0';
			stock += 1;
			break ;
		}
		stock++;
	}
	return (ptr);
}

char	**convert_to_matrix(char *map, int *rows, int *cols)
{
	char	**matrix;
	
	*rows = 0;
	*cols = 0;
	
	char *ptr = map;
	while (*ptr) 
	{
		if (*ptr == '\n') 
		{
			(*rows)++;
       		 }
       		 ptr++;
    	}
    	(*rows)++;

    
    	char *temp = ft_strchr(map, '\n');
    	if (temp)
        	*cols = temp - map;
    	matrix  = malloc(*rows * sizeof(char *));
    	for (int i = 0; i < *rows; i++)
       	{
        	matrix[i] = malloc((*cols + 1) * sizeof(char)); // +1 para o caractere nulo
    	}

    	int row = 0;
   	 char *line = ft_strtok(map, '\n');
    	while (line != NULL)
       	{
        	ft_strcpy(matrix[row], line);
       		row++;
       		line = ft_strtok(NULL, '\n');
   	 }

    return matrix;
}

