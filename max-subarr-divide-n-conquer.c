#include <stdio.h>
#include <limits.h>

int max(int a, int b, int c)
{
    if(a >= b && a >= c)
        return a;
    else if(b >= a && b >= c)
        return b;
    else
        return c;
}

int cross_sum(int *arr, int low, int mid, int high)
{
    int sum = 0;
    int leftsum = INT_MIN;
    int rightsum = INT_MIN;

    for(int i = mid; i >= low; i--)
    {
        sum = *(arr + i) + sum;

        if(sum > leftsum)
            leftsum = sum;
    }

    sum = 0;

    for(int i = mid + 1; i <= high; i++)
    {
        sum = sum + *(arr + i);

        if(sum > rightsum)
            rightsum = sum;
    }

    int cross_sum = rightsum + leftsum;

    return cross_sum;
}

int max_sub_arr_sum(int *arr, int low, int high)
{
    if(low == high)
    {
        return *(arr + low);
    }

    int mid = (low + high) / 2;

    return max(
        max_sub_arr_sum(arr, low, mid),
        max_sub_arr_sum(arr, mid + 1, high),
        cross_sum(arr, low, mid, high)
    );
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};

    int n = sizeof(arr) / sizeof(arr[0]);

    int answer = max_sub_arr_sum(arr, 0, n - 1);

    printf("Maximum contiguous sum is %d\n", answer);

    return 0;
}
