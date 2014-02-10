// sort.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "stdlib.h"
#include <cstdio>
#include <algorithm>

// Heap Sort Implement
void HeapAdjust(int *a,int i,int size)  //\u8c03\u6574\u5806
{
    int lchild=2*i;       //i\u7684\u5de6\u5b69\u5b50\u8282\u70b9\u5e8f\u53f7
    int rchild=2*i+1;     //i\u7684\u53f3\u5b69\u5b50\u8282\u70b9\u5e8f\u53f7
    int max=i;            //\u4e34\u65f6\u53d8\u91cf
    if(i<=size/2)          //\u5982\u679ci\u662f\u53f6\u8282\u70b9\u5c31\u4e0d\u7528\u8fdb\u884c\u8c03\u6574
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
            HeapAdjust(a,max,size);    //\u907f\u514d\u8c03\u6574\u4e4b\u540e\u4ee5max\u4e3a\u7236\u8282\u70b9\u7684\u5b50\u6811\u4e0d\u662f\u5806
        }
    }       
}

void BuildHeap(int *a,int size)    //\u5efa\u7acb\u5806
{
    int i;
    for(i=size/2;i>=1;i--)    //\u975e\u53f6\u8282\u70b9\u6700\u5927\u5e8f\u53f7\u503c\u4e3asize/2
    {
        HeapAdjust(a,i,size);   
    }   
}

void HeapSort(int *a,int size)    //\u5806\u6392\u5e8f
{
    int i;
    BuildHeap(a,size);
    for(i=size;i>=1;i--)
    {
        //cout<<a[1]<<" ";
        std::swap(a[1],a[i]);           //\u4ea4\u6362\u5806\u9876\u548c\u6700\u540e\u4e00\u4e2a\u5143\u7d20\uff0c\u5373\u6bcf\u6b21\u5c06\u5269\u4f59\u5143\u7d20\u4e2d\u7684\u6700\u5927\u8005\u653e\u5230\u6700\u540e\u9762
          //BuildHeap(a,i-1);        //\u5c06\u4f59\u4e0b\u5143\u7d20\u91cd\u65b0\u5efa\u7acb\u4e3a\u5927\u9876\u5806
          HeapAdjust(a,1,i-1);      //\u91cd\u65b0\u8c03\u6574\u5806\u9876\u8282\u70b9\u6210\u4e3a\u5927\u9876\u5806
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
	int array4[] = {6,2,4,7,9,1,0,23,12,5};
	HeapSort(array4, 9);

	printArray(array, 9, "Quick Sort:");
	printArray(array1, 9, "Merge Sort:");
	printArray(array2, 9, "Bubble Sort");
	printArray(array3, 9, "Insert Sort:");
	printArray(array4+1, 9, "Heap Sort:");

	return 0;
}

