#include "../libft.h"

char *ft_strlower(char *str) {
    for (char *p = str; *p; p++) {
        *p = ft_tolower(*p);
    }
    return str;
}