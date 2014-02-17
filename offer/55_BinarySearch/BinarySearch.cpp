#include <cstdio>

int bisearch(int* sorted, int target, int length)
{
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (sorted[middle] < target)
            left = middle + 1;
        if (sorted[middle] > target)
            right = middle - 1;
        if (sorted[middle] == target)
            return middle;
    }

    return -1;
}

int main()
{
    int array[] = {1, 4, 6, 9, 12, 15, 20};
    int foundPos = bisearch(array, 12, 7);

    if (foundPos != -1)
        printf("The element is at %d\n", foundPos);
    
    return 0;
}
