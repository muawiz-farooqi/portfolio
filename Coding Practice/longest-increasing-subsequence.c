#define MAX(a, b) ((a > b) ? a : b)

int find_max(int* nums, int size)
{
    int i,
    max = INT_MIN;

    for (i = 0; i < size; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }

    return max;
}

int lengthOfLIS(int* nums, int numsSize)
{
    if (!numsSize) return 0;

    int n = numsSize,
        arr[n],
        curr = 0,
        max = 0,
        i,
        j;

    for (i = 0; i < n; i++)
    {
        arr[i] = 1;
    }

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                arr[i] = MAX(arr[j] + 1, arr[i]);
            }
        }
    }

    return find_max(arr, n);
}