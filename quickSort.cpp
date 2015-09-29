//
//  quickSort.cpp
//  快速排序
//
//  Created by Zhang Huajun on 29/9/15.
//  Copyright (c) 2015 huajunz. All rights reserved.
//
#include <iostream>

using namespace std;


void qsort(int a[], int left, int right)
{
    int low=left, high=right;
    int pivot = a[low];
    if(left > right) return;
    while(low < high){
        while( low < high && a[high] >= pivot)
            high--;
        a[low] = a[high];
        while(low < high && a[low] <= pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    qsort(a,left,low-1);
    qsort(a, low+1, right);
}

int main()
{
    int n;
    cin>>n;
    int *a=new int[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    qsort(a, 0, n-1);

    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<endl;
    return 0;
}

/* input

10
21 17 29 32 40 16 12 41 9 11

*/


/* output

9 11 12 16 17 21 29 32 40 41

*/

