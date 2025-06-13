#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

#include <stdbool.h>
#include <stdio.h>

typedef enum {
    VALID,
    INVALID
} PwStatus;

PwStatus validate_password(const char *new_pw, const char *curr_pw);

#endif