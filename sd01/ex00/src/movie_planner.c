#include "../includes/movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
    struct Preferences *prefs = get_user_preferences();
    if (!prefs)
        return NULL;

    struct MovieList *list = find_movies(prefs);
    free(prefs);

    if (!list)
        return NULL;

    struct Plan *plan = build_plan(list);
    free(list);

    return plan;
}
