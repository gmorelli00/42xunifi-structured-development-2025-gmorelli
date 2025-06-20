#include "../includes/password_validator.h"

int str_cmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

bool is_uppercase(char c)
{
    return (c >= 'A' && c <= 'Z');
}

bool is_lowercase(char c)
{
    return (c >= 'a' && c <= 'z');
}

bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

bool is_special_char(char c)
{
    const char *special_chars = "@#$%ˆ&*";

    for (int i = 0; special_chars[i]; i++)
    {
        if (c == special_chars[i])
            return true;
    }
    return false;
}

PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
    if (!new_pw || !curr_pw)
        return INVALID;

    int i = 0;
    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_special = false;

    if (str_cmp(new_pw, curr_pw) == 0)
        return INVALID;

    while (new_pw[i])
    {
        if (is_uppercase(new_pw[i]))
            has_upper = true;
        if (is_lowercase(new_pw[i]))
            has_lower = true;
        if (is_digit(new_pw[i]))
            has_digit = true;
        if (is_special_char(new_pw[i]))
            has_special = true;
        i++;
    }

    if (i < 8 || !has_upper || !has_lower || !has_digit || !has_special)
        return INVALID;
    return VALID;
}

// int main(void)
// {
//     const char *current = "MyOldP@ss1";
//     const char *newpass = "MyNewP@ss2";

//     if (validate_password(newpass, current) == VALID)
//         printf("Password valida\n");
//     else
//         printf("Password non valida\n");

//     return 0;
// }
