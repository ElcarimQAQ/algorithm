#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int pd(int x){
    int c=(int)sqrt(x);
    if(c*c==x)
        return 1;
    else
        return 0;
}

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,l,r;
    cin>>t;
    while(t--){
        cin>>l>>r;
        int cnt=0;
        for(int i=l;i<=r;i++){
            int flag=1;
            if(pd(i)){
                //printf("YES");
                int m=i;
                while(m>0){
                    int s=m%10;
                    if(s!=0&&s!=1&&s!=4&&s!=9){
                        flag=0;
                        break;
                    }
                    m/=10;
                }
            }
            else
                flag=0;
            if(flag==1)
                cnt++;
        }
        printf("%d\n",cnt);
    }
     return 0;
}

