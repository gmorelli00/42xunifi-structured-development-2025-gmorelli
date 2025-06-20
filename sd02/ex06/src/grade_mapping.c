#include "../includes/grade_mapping.h"

const char *plusminus_mapper(int score)
{
    if (score >= 97)
        return "A+";
    if (score >= 93)
        return "A";
    if (score >= 90)
        return "A-";
    if (score >= 87)
        return "B+";
    if (score >= 83)
        return "B";
    if (score >= 80)
        return "B-";
    if (score >= 77)
        return "C+";
    if (score >= 73)
        return "C";
    if (score >= 70)
        return "C-";
    if (score >= 67)
        return "D+";
    if (score >= 63)
        return "D";
    if (score >= 60)
        return "D-";
    return "F";
}

const char *passfail_mapper(int score)
{
    return (score >= 60 ? "P" : "F");
}

const char *standard_mapper(int score)
{
    if (score >= 90)
        return "A";
    if (score >= 80)
        return "B";
    if (score >= 70)
        return "C";
    if (score >= 60)
        return "D";
    return "F";
}


void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
    if (!scores || size <= 0)
        return;

    for (int i = 0; i < size; i++)
    {
        if (scores[i] < 0 || scores[i] > 100)
            mapped_grades[i] = "Invalid";
        else
            mapped_grades[i] = mapper(scores[i]);
    }
}

// int main(void) {
//     int scores[] = {85, 92, 77, 58, 99, 101};
//     int size = sizeof(scores) / sizeof(scores[0]);
//     const char *grades[size];

//     map_scores(scores, size, plusminus_mapper, grades);
//     map_scores(scores, size, passfail_mapper, grades);
//     map_scores(scores, size, standard_mapper, grades);

//     for (int i = 0; i < size; i++) {
//         printf("Score: %d → Grade: %s\n", scores[i], grades[i]);
//     }

//     return 0;
// }
