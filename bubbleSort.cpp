//
//  bubbleSort.cpp
//  冒泡排序
//
//  Created by Zhang Huajun on 29/9/15.
//  Copyright (c) 2015 huajunz. All rights reserved.
//
#include <iostream>

using namespace std;

void bubbleSort(int a[], int n) //基本冒泡排序
{
    int tmp;
    for(int i =0 ; i< n-1; ++i) 
    {  
        for(int j = 0; j < n-i-1; ++j) 
        {  
           if(a[j] > a[j+1])  
            {  
                tmp = a[j] ; a[j] = a[j+1] ;  a[j+1] = tmp;  
            }  
        }  
    } 
}

void bubbleSort1(int a[], int n) //改进的冒泡排序，增加exchange表示是否交换过
{
    int tmp;
    bool exchange = true;
    for(int i =0 ; i< n-1 && exchange ; ++i) 
    {  
        exchange =false;
        for(int j = 0; j < n-i-1; ++j) 
        {  
           if(a[j] > a[j+1])  
            {  
                tmp = a[j] ; a[j] = a[j+1] ;  a[j+1] = tmp;  
                exchange = true;
            }  
        }  
    } 
}



void bubbleSort2(int a[], int n)
{
    int k, j,tmp;
    for(int i = n-1; i > 0; i = k) //k记录最后一个交换的位置
    {
        for( k=j=0; j<i; j++)
        {
            if( a[j] > a[j+1])
            {
                tmp = a[j] ; a[j] = a[j+1] ;  a[j+1] = tmp; 
                k = j;  //记录每次交换的位置
            }
        }       
     }
}
    
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    //bubbleSort(a, n);
    //bubbleSort1(a, n);

    bubbleSort2(a, n);

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

