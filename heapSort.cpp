//
//  heapSort.cpp
//  堆排序
//
//  Created by Zhang Huajun on 25/9/15.
//  Copyright (c) 2015 huajunz. All rights reserved.
//

#include <iostream>
using namespace std;

void HeapAdjust(int a[], int start, int end)  //对堆进行调整，使a[start~end]成为一个大顶堆
{
    int temp = a[start];
    for(int i=2*start+1; i<=end; i=i*2+1) //i结点左孩子和右孩子分别为2i+1和2i+2. (因为根结点的序号为0)
    {
        if(i<end && a[i]<a[i+1])  //选取左右孩子中较大值
        {
            i++;
        }
        
        if(temp>a[i]) //根结点最大
        {
            break;
        }

        a[start] = a[i];  //将孩子结点上调，然后以孩子结点的位置进行下一轮的筛选
        start = i;
    }

    a[start]= temp;
}

void HeapSort(int a[], int n)
{   
    int temp;
    for(int i=n/2;i>=0;i--)  //建立大顶堆, 从最后一个非叶结点开始向前调整堆
    {
        HeapAdjust(a,i,n);
    }

    for(i=n;i>0;i--)
    {
        temp=a[i]; a[i]=a[0]; a[0]=temp;
        HeapAdjust(a, 0, i-1);
    }
}

int main()
{
    int N;
    cin>>N;
    int *a=new int[N];

    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }

    HeapSort(a, N-1);

    for(i=0;i<N;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/* input

10
2 1 3 12 21 86 32 5 9 11

*/


/* output

1 2 3 5 9 11 12 21 32 86

*/
