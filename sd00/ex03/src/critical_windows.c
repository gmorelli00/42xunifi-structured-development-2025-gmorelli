#include "../includes/critical_windows.h"
#include <stdio.h>

int is_critical_window(const int *readings, int size)
{
    int count_70x3 = 0;
    int sum = 0; 

    for (int i = 0; i < size; i++)
    {
        if (readings[i] >= 70)
            count_70x3++;
        if (readings[i] > 150)
            return 0;

        sum += readings[i];
    }
    if (count_70x3 >= 3 && (sum / size) >= 90)
        return 1;
    return 0;
}

int count_critical_windows(const int *readings, int size)
{
    if (!readings || size <= 5)
        return 0;

    int critical_windows = 0;

    for (int i = 0; i <= size - 5; i++)
    {
        critical_windows += is_critical_window(&readings[i], 5);
    }
    return critical_windows;
}


// int main(void)
// {
//     int readings[] = {80, 95, 100, 88, 92, 60, 70, 85, 72, 91};
//     int size = sizeof(readings) / sizeof(readings[0]);

//     int result = count_critical_windows(readings, size);
//     printf("Critical windows: %d\n", result); // atteso: 2

//     return 0;
// }
