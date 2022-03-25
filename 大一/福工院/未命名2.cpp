#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
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
        scanf("%d%d%d%d%d%d",&h1,&m1,&s1,&h2,&m2,&s2);
        int s;
        s=zh(h2,m2,s2)-zh(h1,s1,m1);

        if(s>0){
            printf("Case #%d: %d\n",i,s);
        }
        else
            printf("Case #%d: %d\n",i,86400+s);
    }
    return 0;
}
