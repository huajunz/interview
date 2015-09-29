//
//  is_include.cpp
//  判断B串中的字符是否都在A串中出现过
//
//  Created by Zhang Huajun on 29/9/15.
//  Copyright (c) 2015 huajunz. All rights reserved.
//
#include <string>
#include <iostream>

using namespace std;

int convert(char *str)
{
    int A=0;
    char s;
    int pos=0;
    while(*str!='\0')
    {
        s=tolower(*str);
        pos=s-'a';
        A|=(1<<pos);
        str++;
    }
    return A;
}

int is_include(char *a,char *b)
{
    int A,B,C,D;
    A=convert(a);
    B=convert(b);
    C=A|B;
    D=A^C;
    return D==0?1:0;
}

int main()
{
    
    char *str1, *str2;
    string s1,s2;
    cin>>s1>>s2;
    str1=&s1[0];
    str2=&s2[0];
    printf("%d\n", is_include(str1, str2));
    return 0;
}

/* input

aaaa我bbccdddss
ab我c

*/

/* output

1

*/
