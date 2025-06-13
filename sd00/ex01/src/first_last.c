#include "../includes/first_last.h"

void first_last(int arr[], int size, int target, int *first, int *last)
{
    if (size <= 0 || !arr)
    {
        *first = -1;
        *last = -1;
        return;
    }

    bool first_found = false;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target && !first_found)
        {
            *first = i;
            first_found = true;
        }
        if (arr[i] == target && first_found)
            *last = i;
    }
}

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 3, 6, 3, 7, 8};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int target = 3;
//     int first = -1;
//     int last = -1;

//     first_last(arr, size, target, &first, &last);

//     if (first != -1 && last != -1)
//     {
//         printf("First occurrence: %d\n", first);
//         printf("Last occurrence: %d\n", last);
//     }
//     else
//     {
//         printf("Target not found.\n");
//     }

//     return 0;
// }