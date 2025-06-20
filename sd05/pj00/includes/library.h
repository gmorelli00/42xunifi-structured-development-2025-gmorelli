#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 1000
#define BUFFER_SIZE 1024

#include "book.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

t_book *create_book_node(int id, char *title, char *author);
t_book *load_catalog(const char *filename);
void free_catalog(t_book *catalog);

int is_valid_menu_option(const char *input);
int is_valid_search_string(const char *input);

t_book *search_by_title(t_book *catalog, const char *substring);
t_book *search_by_author(t_book *catalog, const char *substring);

void display_books(t_book *books);
void display_menu();

char *trim_whitespace(char *str);

#endif