#include "../includes/library.h"

t_book *create_book_node(int id, char *title, char *author) {
    t_book *new_book = malloc(sizeof(t_book));
    if (!new_book) return NULL;
    
    new_book->id = id;
    new_book->title = ft_strdup(title);
    new_book->author = ft_strdup(author);
    new_book->next = NULL;
    
    if (!new_book->title || !new_book->author) {
        free(new_book->title);
        free(new_book->author);
        free(new_book);
        return NULL;
    }
    
    return new_book;
}

void free_catalog(t_book *catalog) {
    t_book *tmp;
    while (catalog) {
        tmp = catalog;
        catalog = catalog->next;
        free(tmp->title);
        free(tmp->author);
        free(tmp);
    }
}

t_book *load_catalog(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        ft_printf("Error opening file\n");
        return NULL;
    }

    t_book *catalog = NULL;
    t_book *tail = NULL;
    char *line;
    int count = 0;

    while ((line = get_next_line(fd)) && count < MAX_BOOKS) {
        char *trimmed = ft_strtrim(line, " \t\n\r");
        free(line);
        
        if (ft_strlen(trimmed) == 0) {
            free(trimmed);
            continue;
        }

        char **parts = ft_split(trimmed, ',');
        free(trimmed);
        
        if (!parts || !parts[0] || !parts[1] || !parts[2]) {
            ft_printf("Warning: Malformed line\n");
            ft_free_split(parts);
            continue;
        }

        char *id_str = ft_strtrim(parts[0], " \t");
        char *title = ft_strtrim(parts[1], " \t");
        char *author = ft_strtrim(parts[2], " \t");
        
        if (!ft_isdigit(*id_str)) {
            ft_printf("Warning: Invalid ID\n");
            ft_free_split(parts);
            continue;
        }

        int id = ft_atoi(id_str);
        t_book *new_book = create_book_node(id, title, author);
        ft_free_split(parts);

        if (!new_book) {
            ft_printf("Error: Memory allocation failed\n");
            close(fd);
            free_catalog(catalog);
            return NULL;
        }

        if (!catalog) {
            catalog = new_book;
            tail = new_book;
        } else {
            tail->next = new_book;
            tail = new_book;
        }
        count++;
    }

    close(fd);
    return catalog;
}