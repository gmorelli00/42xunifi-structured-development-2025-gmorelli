#include "../includes/segmented_runs.h"

int count_segments(const int *arr, int size)
{
    if (size <= 0 || !arr)
        return 0;

    int i = 1;
    int count = 0;
    int segment_length = 1;
    bool has_segment = false;

    while (i < size)
    {
        while (i < size && arr[i] == -1)
        {
            has_segment = false;
            i++;
        }

        if (has_segment == false)
        {
            if (arr[i - 1] < arr[i] && arr[i] - arr[i - 1] == 1 && arr[i - 1] != -1)
                segment_length++;
        }
        
        if (segment_length >= 3)
        {
            segment_length = 1;
            has_segment = true;
            count++;
        }
        i++;
    }
    return count;
}

// int main(void)
// {
//     int a[] = {-1, -1, -1};
//     int b[] = {-1, 1, 1, 1, -1};
//     int c[] = {1, -1, 2, -1, 3};

//     int d[] = {1, 2, 3};
//     int e[] = {-1, 5, 6, 7, -1};
//     int f[] = {-1, 9, 10, 11, 8, 9, 10, -1};

//     int g[] = {-1, 1, 2, 3, -1, 5, 6, 7, -1};
//     int h[] = {1, 2, 3, -1, 0, 1, 2};

//     int i[] = {-1, 1, 3, 5, 7, -1};

//     int result = count_segments(a, sizeof(a) / sizeof(a[0]));
//     printf("Segments with increasing sequence of length ≥ 3: %d\n", result);
//     result = count_segments(b, sizeof(b) / sizeof(b[0]));
//     printf("Segments with increasing sequence of length ≥ 3: %d\n", result);
//     result = count_segments(c, sizeof(c) / sizeof(c[0]));
//     printf("Segments with increasing sequence of length ≥ 3: %d\n", result);
//     result = count_segments(d, sizeof(d) / sizeof(d[0]));
//     printf("Segments with increasing sequence of length ≥ 3: %d\n", result);
//     result = count_segments(e, sizeof(e) / sizeof(e[0]));
//     printf("Segments with increasing sequence of length ≥ 3: %d\n", result);
//     result = count_segments(f, sizeof(f) / sizeof(f[0]));
//     printf("Segments with increasing sequence of length ≥ 3: %d\n", result);
//     result = count_segments(g, sizeof(g) / sizeof(g[0]));
//     printf("Segments with increasing sequence of length ≥ 3: %d\n", result);
//     result = count_segments(h, sizeof(h) / sizeof(h[0]));
//     printf("Segments with increasing sequence of length ≥ 3: %d\n", result);
//     result = count_segments(i, sizeof(i) / sizeof(i[0]));
//     printf("Segments with increasing sequence of length ≥ 3: %d\n", result);
//     return 0;
// }
