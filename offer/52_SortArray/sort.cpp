// sort.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "stdlib.h"
#include <cstdio>
#include <algorithm>

template <class T>
void MySwap(T& a, T& b)
{
    T temp = b;
    b = a;
    a = temp;
}

int partition(int *data, int left, int right)
{
    int length = right - left + 1;

    int index = left;
    MySwap<int>(data[left], data[right]);

    int small = left - 1;
    for(int i = left; i < right; i++) {
        if(data[i] < data[right]) {
            if(small != i) {
                MySwap(data[i], data[++small]);
            }
        }
    }

    MySwap(data[++small], data[right]);

    return small;
}

void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = partition(s, l, r);
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}

/////////////////归并排序////////////////////////////////////////////
//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergearray(int a[], int first, const int mid, const int last)
{
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;
    //int temp[8+1];
	//int* temp = (int*)malloc(last+1);
	int* temp = new int[last+1];
    while (i <= m && j <= n)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= n)
        temp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[first + i] = temp[i];

	delete temp;
	//free(temp);
}

void mergesort(int a[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(a, first, mid);    //左边有序
        mergesort(a, mid + 1, last); //右边有序
        mergearray(a, first, mid, last); //再将二个有序数列合并
    }
}

//////////////////////////////////////////////////////////////////
/////////////////////直接插入法////////////////////////////////////
void Insertsort(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
        for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--) {
            int temp = a[j + 1];
            a[j+1] = a[j];
            a[j] = temp;
        }
}

//////////////////////////////////////////////////////////////
//////////////////////////////冒泡排序/////////////////////////
void BubbleSort(int a[], int n)
{
       int i, j;
       for (i = 0; i < n; i++)                         //n
              for (j = 1; j < n - i; j++)
                     if (a[j - 1] > a[j]) {
                         int temp = a[j - 1];
                         a[j-1] = a[j];
                         a[j] = temp;
                     }
}

void printArray(int* array, int length, const char* description)
{
	printf("%s", description);
	for(int i = 0; i < length; i++) {
		printf("%d\t", *(array+i));
	}
	printf("\n");
}

int main(int argc, char* argv[])
{
	int array[] = {2,4,7,9,1,0,23,12,5};
	quick_sort(array, 0, 8);
	int array1[] = {2,4,7,9,1,0,23,12,5};
	mergesort(array1, 0, 8);
	int array2[] = {2,4,7,9,1,0,23,12,5};
	BubbleSort(array2, 9);
	int array3[] = {2,4,7,9,1,0,23,12,5};
	Insertsort(array3, 9);

	printArray(array, 9, "Quick Sort:");
	printArray(array1, 9, "Merge Sort:");
	printArray(array2, 9, "Bubble Sort");
	printArray(array3, 9, "Insert Sort:");
	return 0;
}

