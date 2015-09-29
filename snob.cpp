//
//  snob.cpp
//  给定一个数，找出一个比它大，而且值为1的位元数与之相同的数字
//
//  Created by Zhang Huajun on 29/9/15.
//  Copyright (c) 2015 huajunz. All rights reserved.
//
#include <string>
#include <iostream>

using namespace std;

unsigned snob(unsigned x)
{
    unsigned smallest, ripple, ones;    //x= xxx0 1111 0000
    smallest = x & -x;                  //   0000 0001 0000
    ripple = x + smallest;              //   xxx1 0000 0000
    ones = x ^ ripple;                  //   0001 1111 0000
    ones = ( ones>>2 ) / smallest;      //   0000 0000 0111  右移两位(去除多的1)，然后除以smallest(相当于s后面有几个0，右移多少位)
    return ripple | ones;               //   xxx1 0000 0111
}

int main()
{
    
    unsigned a,b;
    cin>>a;
    b=snob(a);
    cout<<b<<endl;
    return 0;
}

/* input

5

*/

/* output

6

*/
