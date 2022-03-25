
#include <bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
#define INF 0x3f3f3f3f
const int maxn=100005;
using namespace std;
typedef long long ll;
int a[maxn];
int n;
int check(int x){
    int b[maxn];
    int j=1;
    for(int i=2;i<=n;i+=2){
        b[i]=a[j];
        j++;
    }
    cout<<j<<endl;
    if(j>x)
        return 1;
    else
        return 0;
}
int main(){

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int l=1;
    int r=n;
    while(l<=r){
        int m=(l+r)/2;
        //cout<<m<<endl;
        if(check(m)){
            l=m+1;
        }
        else{
            r=m-1;
        }

    }
    cout<<l<<endl;
    return 0;
}
