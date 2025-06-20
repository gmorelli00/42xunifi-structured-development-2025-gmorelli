#include "../includes/main.h"

static char *get_input(int fd) {
    char *input = get_next_line(fd);
    if (input) {
        char *trimmed = ft_strtrim(input, "\n");
        free(input);
        return trimmed;
    }
    return NULL;
}

int run_program(const char *filename) {
    t_book *catalog = load_catalog(filename);
    if (!catalog) {
        return EXIT_FAILURE;
    }

    char *choice = NULL;
    char *search_term = NULL;
    t_book *results = NULL;

    while (1) {
        display_menu();
        choice = get_input(STDIN_FILENO);
        if (!choice) break;

        if (!is_valid_menu_option(choice)) {
            ft_printf("Invalid choice. Please enter 1 or 2.\n");
            free(choice);
            continue;
        }

        ft_printf("Enter search term: ");
        search_term = get_input(STDIN_FILENO);
        if (!search_term) {
            free(choice);
            break;
        }

        if (!is_valid_search_string(search_term)) {
            ft_printf("Search term cannot be empty.\n");
            free(choice);
            free(search_term);
            continue;
        }

        if (ft_strcmp(choice, "1") == 0) {
            results = search_by_title(catalog, search_term);
        } else {
            results = search_by_author(catalog, search_term);
        }

        display_books(results);
        free_catalog(results);
        results = NULL;

        ft_printf("\nPerform another search? (y/n): ");
        free(choice);
        free(search_term);
        choice = get_input(STDIN_FILENO);
        if (!choice) break;

        if (ft_tolower(choice[0]) != 'y') {
            free(choice);
            break;
        }
        free(choice);
    }

    free_catalog(catalog);
    return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        ft_printf("Usage: %s <catalog_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    return run_program(argv[1]);
}