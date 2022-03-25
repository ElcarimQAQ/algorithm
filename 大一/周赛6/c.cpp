#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
int a[100005];

int found(int l,int key) {

    int left = 1;
    int right = l;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] == key) {
            return 1;
        }
        if (a[mid] < key)
            left = mid + 1;
        if (a[mid] > key)
            right = mid - 1;

    }
    return 0;
}

int main(){

    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        if (found(n,x)==0)
            printf("Case #%d:Don't xia BB!\n",i);
        else
            printf("Case #%d:You are real cai!\n",i);
    }
    return 0;
}


