//
//  packageDP.c
//  0-1背包问题——动态规划
//
//  Created by Zhang Huajun on 25/9/15.
//  Copyright (c) 2015 huajunz. All rights reserved.
//
#include <stdio.h>
#include <iostream>
using namespace std;

int v[200][200];//前i个物品装入容量为j的背包中获得的最大价值

int max(int a,int b)
{
    return a>b?a:b;
}

int KnapSack(int n,int w[],int p[],int x[],int M)
{
    int i,j;
    for(i=0;i<=n;i++)   v[i][0]=0;
    for(j=0;j<=M;j++)   v[0][j]=0;

    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=M;j++)
        {
            if(j<w[i])  //第i件物品大于 背包所余容量 ,则不选
                v[i][j]=v[i-1][j];
            else //若第i件物品能够放入背包
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
        }
    }

    j=M;
    for(i=n-1;i>=0;i--)
    {
        if(v[i][j]>v[i-1][j]) //放入第i件物品使得总价值增加了
        {
            x[i]=1;
            j=j-w[i];
        }
        else x[i]=0;
    }
  
    for(i=0;i<n;i++)
        printf("%d ",x[i]);
    printf("\n");
    return v[n-1][M];     
}

void main()
{
    int s;//获得的最大价值
    int w[15];//物品的重量
    int p[15];//物品的价值
    int x[15];//物品的选取状态
    int n,i;
    int M;//背包最大容量

    scanf("%d %d",&M, &n);

    for(i=0;i<n;i++)
        scanf("%d",&w[i]);

    for(i=0;i<n;i++)
        scanf("%d",&p[i]);

    s=KnapSack(n,w,p,x,M);

    printf("%d\n",s); 
}

/* input

5 4
2 1 3 2
3 2 4 2

*/


/* output

0 1 0 1
7

*/

