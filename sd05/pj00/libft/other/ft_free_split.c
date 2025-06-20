#include "../libft.h"

void ft_free_split(char **split) {
    for (int i = 0; split[i]; i++) {
        free(split[i]);
    }
    free(split);
}