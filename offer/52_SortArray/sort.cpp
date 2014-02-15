// sort.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "stdlib.h"
#include <cstdio>
#include <algorithm>

// Heap Sort Implement
void HeapAdjust(int *a,int i,int size)
{
    int lchild=2*i;      
    int rchild=2*i+1;     
    int max=i;            
    if(i<=size/2)          
    {
        if(lchild<=size&&a[lchild]>a[max])
        {
            max=lchild;
        }   
        if(rchild<=size&&a[rchild]>a[max])
        {
            max=rchild;
        }
        if(max!=i)
        {
            std::swap(a[i],a[max]);
            HeapAdjust(a,max,size);    
        }
    }       
}

void BuildHeap(int *a,int size)    
{
    int i;
    for(i=size/2;i>=1;i--)    
    {
        HeapAdjust(a,i,size);   
    }   
}

void HeapSort(int *a,int size)    
{
    int i;
    BuildHeap(a,size);
    for(i=size;i>=1;i--)
    {
        std::swap(a[1],a[i]);           
        HeapAdjust(a,1,i-1);      
    }
}

// Quick Sort Implement
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
        quick_sort(s, l, i - 1); 
        quick_sort(s, i + 1, r);
    }
}

void mergearray(int a[], int first, const int mid, const int last)
{
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;
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
}

void mergesort(int a[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(a, first, mid);    
        mergesort(a, mid + 1, last); 
        mergearray(a, first, mid, last); 
    }
}

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

void BubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)       
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
	int array4[] = {6,2,4,7,9,1,0,23,12,5};
	HeapSort(array4, 9);

	printArray(array, 9, "Quick Sort:");
	printArray(array1, 9, "Merge Sort:");
	printArray(array2, 9, "Bubble Sort");
	printArray(array3, 9, "Insert Sort:");
	printArray(array4+1, 9, "Heap Sort:");

	return 0;
}

