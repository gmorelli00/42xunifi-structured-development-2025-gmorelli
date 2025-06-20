#include "../includes/library.h"

int is_valid_search_string(const char *input) {
    if (!input) return 0;
    return ft_strlen(trim_whitespace((char *)input)) > 0;
}

t_book *search_by_title(t_book *catalog, const char *substring) {
    if (!catalog || !substring) return NULL;

    t_book *results = NULL;
    t_book *tail = NULL;
    char *lower_sub = ft_strdup(substring);
    ft_strlower(lower_sub);

    while (catalog) {
        char *lower_title = ft_strdup(catalog->title);
        ft_strlower(lower_title);

        if (ft_strnstr(lower_title, lower_sub, ft_strlen(lower_title))) {
            t_book *new_node = create_book_node(catalog->id, catalog->title, catalog->author);
            if (!new_node) {
                free(lower_title);
                free(lower_sub);
                free_catalog(results);
                return NULL;
            }

            if (!results) {
                results = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        free(lower_title);
        catalog = catalog->next;
    }

    free(lower_sub);
    return results;
}

t_book *search_by_author(t_book *catalog, const char *substring) {
    if (!catalog || !substring) return NULL;

    t_book *results = NULL;
    t_book *tail = NULL;
    char *lower_sub = ft_strdup(substring);
    ft_strlower(lower_sub);

    while (catalog) {
        char *lower_author = ft_strdup(catalog->author);
        ft_strlower(lower_author);

        if (ft_strnstr(lower_author, lower_sub, ft_strlen(lower_author))) {
            t_book *new_node = create_book_node(catalog->id, catalog->title, catalog->author);
            if (!new_node) {
                free(lower_author);
                free(lower_sub);
                free_catalog(results);
                return NULL;
            }

            if (!results) {
                results = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        free(lower_author);
        catalog = catalog->next;
    }

    free(lower_sub);
    return results;
}