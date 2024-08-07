#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função auxiliar para encontrar o mínimo de três números
int	min(int a, int b, int c) 
{
	int	l;

	if (a < b)
		l = a;
	else
		l = b;
	if (l < c)
		return (l);
	else
		return (c);
}

int	max_matrix_size(char **arr, int rows, int cols)
{
	int	result[rows][cols];
	int	max;
	int	max_i;
	int	max_j;
	int	i;
	int	j;

	max = 0;
	max_i = -1;
	max_j = -1;
	i = 0;
	j = 0;
    while (i < rows)
    {
        result[i][0] = (arr[i][0] == '.') ? 1 : 0;
        if (result[i][0] > max)
	{
            max = result[i][0];
            max_i = i;
            max_j = 0;
        }
        i++;
    }
    while (j < cols)
    {
        result[0][j] = (arr[0][j] == '.') ? 1 : 0;
        if (result[0][j] > max)
	{
            max = result[0][j];
            max_i = 0;
            max_j = j;
        }
        j++;
    }
    i = 1;
    while (i < rows)
    {
        j = 1;
        while (j < cols) {
            if (arr[i][j] == 'o')
	    {
                result[i][j] = 0;
            }
	    else 
	    {
                result[i][j] = min(result[i-1][j], result[i-1][j-1], result[i][j-1]) + 1;
                if (result[i][j] > max)
		{
                    max = result[i][j];
                    max_i = i;
                    max_j = j;
                }
            }
            j++;
        }
        i++;
    }
    i = max_i;
    while (i > max_i - max)
    {
        j = max_j;
        while (j > max_j - max)
	{
            arr[i][j] = 'x';
            j--;
        }
        i--;
    }

    return max;
}



int	max_sub_matrix(char **matrix_map, int rows, int cols) 
{
	char	**arr;

    cols = strlen(matrix_map[0]);

    arr = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        arr[i] = malloc((cols + 1) * sizeof(char));
        strcpy(arr[i], matrix_map[i]);
    }

    int result = max_matrix_size(arr, rows, cols);
    printf("Maximum submatrix size: %d\n", result);

    for (int i = 0; i < rows; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }
    free(arr);

    return 0;
}
