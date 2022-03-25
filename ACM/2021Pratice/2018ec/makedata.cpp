#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
typedef long long ll;
#define mod 100000007

int main ()
{

    freopen("data.in","w",stdout);
    srand(time(NULL));
    int t=rand()%10+1;
    printf("%d\n",t);
    while(t--){
        int n=rand()%20+1;
        printf("%d\n",n);
        for(int i = 1;i <= n; i++){
            int a=rand()%10+1;
            printf("%d ",a);
        }
    }
    return 0;
}
