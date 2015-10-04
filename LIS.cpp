//
//  LIS.cpp
//  最长递增子序列（LIS）
//    对于一个给定序列，求一个最长的子序列，使得子序列中的所有元素递增.
//    例如，{10，22，9，33，21，50，41，60，80}  LIS的长度是6 , LIS为{10，22，33，50，60，80}
//  Created by Zhang Huajun on 4/10/15.
//  Copyright (c) 2015 huajunz. All rights reserved.
//
#include <iostream>

using namespace std;

int LIS(int a[], int n, int ret[])
{
    int *maxlen = new int [n];  //存放以第i个元素结尾的LIS
    int *pre = new int [n]; 
    int len=0 ,maxindex=0;
    for(int i=0;i<n;i++) 
    {   
        maxlen[i]=1;
        pre[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i] && maxlen[j]+1 > maxlen[i]) 
            {
                maxlen[i]=maxlen[j]+1;
                pre[i]=j;    //表示以第i个元素结尾的LIS 是由第j个元素的maxlen加1得到的
            }
        }
    }

    for(i=0;i<n;i++)  
    {
        if(maxlen[i]>len) 
        {
            len = maxlen[i];
            maxindex = i;
        }
    }

    for(i=len-1;i>=0;i--)
    {
        ret[i]=a[maxindex]; 
        maxindex = pre[maxindex];
    }

    return len;

}

int main()
{
    int n,maxlen=0;
    cin>>n;

    int *a = new int [n];
    int *ret = new int [n]; 
    for(int i=0;i<n;i++) ret[i]=-1;

    for(i=0;i<n;i++) cin>>a[i];
    
    maxlen=LIS(a,n,ret);

    cout<<maxlen<<endl;

    for(i=0;i<maxlen;i++)
    {
        cout<<ret[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}

/*input 

9
10 22 9 33 21 50 41 60 80

*/

/*output 

6
10 22 33 50 60 80

*/


