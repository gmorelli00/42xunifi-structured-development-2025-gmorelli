#include "../includes/library.h"

char *trim_whitespace(char *str) {
    if (!str) return NULL;
    
    while (ft_isspace(*str)) str++;
    
    if (*str == 0) return str;
    
    char *end = str + ft_strlen(str) - 1;
    while (end > str && ft_isspace(*end)) end--;
    
    *(end + 1) = '\0';
    return str;
}