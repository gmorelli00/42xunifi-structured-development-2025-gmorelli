#include "../includes/music_organizer.h"

struct MusicLibrary *organize_music_library(const char *directory_path)
{
    if (!directory_path)
        return NULL;

    struct MusicLibrary *library = create_music_library();
    if (!library)
        return NULL;

    const char **filenames = scan_directory(directory_path);
    if (!filenames) {
        free(library);
        return NULL;
    }

    for (int i = 0; filenames[i] != NULL; i++) {
        struct MusicFile *song = process_music_file(directory_path, filenames[i]);
        if (song) {
            update_music_library(library, song);
            free(song);
        }
    }

    free(filenames);
    return library;
}
