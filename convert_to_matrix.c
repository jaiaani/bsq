#include <stdlib.h>

int	ft_strlen(char *srt);

char *ft_strcpy(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++));
    return dest;
}

char *ft_strdup(char *str) 
{
    char *dup = malloc(ft_strlen(str) + 1);
    if (dup) {
        ft_strcpy(dup, str);
    }
    return dup;
}

char *ft_strchr(const char *s, int c) {
    while (*s) {
        if (*s == c) {
            return (char *)s;
        }
        s++;
    }
    return NULL;
}

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

char **convert_to_matrix(char *map, int *rows, int *cols) {
    char **matrix;

    *rows = 0;
    *cols = 0;

    char *ptr = map;
    while (*ptr) {
        if (*ptr == '\n') {
            (*rows)++;
        }
        ptr++;
    }
    (*rows)++; 

    char *temp = ft_strchr(map, '\n');
    if (temp) {
        *cols = temp - map;
    }

    matrix = malloc(*rows * sizeof(char *));
    for (int i = 0; i < *rows; i++) {
        matrix[i] = malloc((*cols + 1) * sizeof(char));
   
    int row = 0;
    char *line = ft_strtok(map, "\n");
    while (line != NULL) {
        ft_strcpy(matrix[row], line);
        row++;
        line = ft_strtok(NULL, "\n");
    }

    return matrix;
}


