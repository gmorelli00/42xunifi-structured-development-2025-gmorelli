#include "../includes/workout_scheduler.h"

struct WorkoutPlan *create_workout_schedule(char *username)
{
    if (!username)
        return NULL;

    struct UserData *user = get_user_data(username);
    if (!user)
        return NULL;

    struct WorkoutPlan *plan = build_base_plan(user);
    if (!plan) {
        free_user_data(user);
        return NULL;
    }

    plan = refine_plan(plan, user);
    if (!plan) {
        free_user_data(user);
        return NULL;
    }

    int days = determine_duration(plan);
    if (days <= 0) {
        free_user_data(user);
        free_workout_plan(plan);
        return NULL;
    }

    for (int i = 1; i <= days; i++) {
        assign_daily_exercises(plan, i);
        assign_daily_tips(plan, i);
    }

    free_user_data(user);
    return plan;
}
