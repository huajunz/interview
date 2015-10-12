//
//  mergeSort.cpp
//  归并排序
//
//  Created by Zhang Huajun on 12/10/15.
//  Copyright (c) 2015 huajunz. All rights reserved.
//
#include <iostream>

using namespace std;

  
void merge(int a[], int first, int mid, int last, int temp[])  
{  
    int i = first, j = mid + 1;  
    int m = mid,   n = last;  
    int k = 0;  
      
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
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
}  

void mergesort(int a[], int first, int last, int temp[])  
{  
    if (first < last)  
    {  
        int mid = (first + last) / 2;  
        mergesort(a, first, mid, temp);    
        mergesort(a, mid + 1, last, temp); 
        merge(a, first, mid, last, temp); 
    }  
}  
  
int main()
{  
    int a[10] = {3,1,5,7,2,4,9,6,10,8};  
    int b[10];  
    mergesort(a, 0, 9, b); 
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}  
