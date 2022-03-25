#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int judge(int h1,int m1,int s1,int h2,int m2,int s2){
    if(h2<h1)
        return 1;
    else if(h2==h1&&m2<m1)
        return 1;
    else if(h2==h1&&m1==m2&&s2<=s1)
        return 1;
    else
        return 0;
}
int zh(int x,int y,int z){
    return x*3600+y*60+z;
}

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,h1,m1,s1,h2,m2,s2;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>h1>>m1>>s1>>h2>>m2>>s2;
        if(judge(h1,m1,s1,h2,m2,s2)==0){
            printf("Case #%d: %d\n",i,zh(h2,m2,s2)-zh(h1,s1,m1));
        }
        else
            printf("Case #%d: %d\n",i,86400-zh(h1,m1,s1)+zh(h2,s2,m2));
    }
    return 0;
}

