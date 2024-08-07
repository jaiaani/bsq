#include <stdlib.h>

int	ft_strlen(char *srt);

char *ft_strcpy(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++));
    return dest;
}

// Duplicar uma string
char *ft_strdup(char *str) 
{
    char *dup = malloc(ft_strlen(str) + 1);
    if (dup) {
        ft_strcpy(dup, str);
    }
    return dup;
}

// Encontrar a primeira ocorrência de um caractere em uma string
char *ft_strchr(const char *s, int c) {
    while (*s) {
        if (*s == c) {
            return (char *)s;
        }
        s++;
    }
    return NULL;
}

// Dividir uma string em tokens
char *ft_strtok(char *str, const char *delim) {
    static char *last;
    if (str) {
        last = str;
    }
    if (!last) {
        return NULL;
    }

    char *token = last;
    while (*last) {
        for (const char *d = delim; *d; d++) {
            if (*last == *d) {
                *last = '\0';
                last++;
                if (token != last - 1) {
                    return token;
                } else {
                    token = last;
                    break;
                }
            }
        }
        last++;
    }

    if (token == last) {
        last = NULL;
    }
    return token;
}

// Copiar uma string para outra


char **convert_to_matrix(char *map, int *rows, int *cols) {
    char **matrix;

    *rows = 0;
    *cols = 0;

    // Contar o número de linhas
    char *ptr = map;
    while (*ptr) {
        if (*ptr == '\n') {
            (*rows)++;
        }
        ptr++;
    }
    (*rows)++; // Para a última linha que não termina com '\n'

    // Encontrar o número de colunas (assumindo que todas as linhas têm o mesmo comprimento)
    char *temp = ft_strchr(map, '\n');
    if (temp) {
        *cols = temp - map;
    }

    // Alocar memória para a matriz
    matrix = malloc(*rows * sizeof(char *));
    for (int i = 0; i < *rows; i++) {
        matrix[i] = malloc((*cols + 1) * sizeof(char)); // +1 para o caractere nulo
    }

    // Preencher a matriz com os dados da string
    int row = 0;
    char *line = ft_strtok(map, "\n");
    while (line != NULL) {
        ft_strcpy(matrix[row], line);
        row++;
        line = ft_strtok(NULL, "\n");
    }

    return matrix;
}


