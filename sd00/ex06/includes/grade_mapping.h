#ifndef GRADE_MAPPING_H
#define GRADE_MAPPING_H

// #include <stdio.h>

typedef const char *(*GradeMapper)(int score);

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

#endif