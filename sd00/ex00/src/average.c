#include "../includes/average.h"

float average(const int *arr, int size)
{
    if (size <= 0 || !arr)
        return 0.0f;

    int sum = 0;
    int count = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0 && arr[i] <= 100)
        {
            sum += arr[i];
            count++;
        }
    }

    if (count == 0)
        return 0.0f;

    return (float)sum / count;
}