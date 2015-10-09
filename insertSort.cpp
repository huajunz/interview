//
//  insertSort.cpp
//  插入排序
//
//  Created by Zhang Huajun on 9/10/15.
//  Copyright (c) 2015 huajunz. All rights reserved.
//
#include <iostream> 

using namespace std;


void InsertSort(int a[], int n)  
{  
    for(int i= 1; i<n; i++)
    {  
        if(a[i] < a[i-1]) //若第i个元素小于第i-1个元素，移动有序表后插入
        {               
            int j= i-1;   
            int x = a[i];        //复制为哨兵，即存储待排序元素
            a[i] = a[i-1];       //先 后移一个元素
            while(x < a[j])      //在有序表中寻找插入位置
            {  
                a[j+1] = a[j];   //元素后移
                j--;         
            }  
            a[j+1] = x;          //插入到正确位置
        }  
    }  
}  
  

int main()
{  
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    InsertSort(a,n);  

    for(i=0;i<n;i++)
        cout<<a[i]<<" "; 
    cout<<endl;
    return 0;
} 

/* input

5
4 7 8 6 9

*/


/* output

4 6 7 8 9

*/
