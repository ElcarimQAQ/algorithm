#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
int a[1005];
int main (){
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int n,m;
    int s,s1,cnt1,cnt2;
    while(~scanf("%d",&n)){
        s=0;
        cnt1=cnt2=0;
        scanf("%d",&m);
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            if(a[i]==0&&cnt1==0){
                s1=i;
                cnt1++;
            }
            if(i>=m){
                if(a[i]==0&&cnt2==0){
                    s=i;
                    cnt2++;
                }
            }
        }
            if(s>=m)
                printf("%d\n",s);
            else
                printf("%d\n",s1);


    }
    return 0;
}


