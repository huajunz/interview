//
//  insertSort.cpp
//  希尔排序
//
//  Created by Zhang Huajun on 9/10/15.
//  Copyright (c) 2015 huajunz. All rights reserved.
//
#include <iostream> 

using namespace std;


void shellInsertSort(int a[], int n, int d)  
{  
    for(int i= 1; i<n; i++)
    {  
        if(a[i] < a[i-d])
        {               //ÈôµÚi¸öÔªËØ´óÓÚi-1ÔªËØ£¬Ö±½Ó²åÈë¡£Ð¡ÓÚµÄ»°£¬ÒÆ¶¯ÓÐÐò±íºó²åÈë  
            int j= i-d;   
            int x = a[i];        //¸´ÖÆÎªÉÚ±ø£¬¼´´æ´¢´ýÅÅÐòÔªËØ  
            a[i] = a[i-d];           //ÏÈºóÒÆÒ»¸öÔªËØ  
            while(x < a[j]) //²éÕÒÔÚÓÐÐò±íµÄ²åÈëÎ»ÖÃ  
            {  
                a[j+d] = a[j];  //ÔªËØºóÒÆ  
                j-=d;         
            }  
            a[j+d] = x;      //²åÈëµ½ÕýÈ·Î»ÖÃ  
        }  
    }  
}  
  
void shellSort(int a[], int n){  
  
    int dk = n/2;  
    while( dk >= 1  )
    {  
        shellInsertSort(a, n, dk);  
        dk = dk/2;  
    }  
}

int main()
{  
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    shellSort(a,n);  

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
