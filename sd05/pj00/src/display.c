#include "../includes/library.h"

int is_valid_menu_option(const char *input) {
    return (ft_strcmp((char *)input, "1") == 0 || 
           ft_strcmp((char *)input, "2") == 0);
}

void display_books(t_book *books) {
    if (!books) {
        ft_printf("No books found.\n");
        return;
    }

    ft_printf("\nSearch Results:\n");
    ft_printf("ID\tTitle\t\tAuthor\n");
    ft_printf("----------------------------------------\n");
    while (books) {
        ft_printf("%d\t%s\t%s\n", books->id, books->title, books->author);
        books = books->next;
    }
}

void display_menu() {
    ft_printf("\nCommunity Digital Library\n");
    ft_printf("1. Search by title\n");
    ft_printf("2. Search by author\n");
    ft_printf("Enter your choice (1 or 2): ");
}