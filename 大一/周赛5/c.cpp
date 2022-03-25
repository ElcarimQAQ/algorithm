#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[10005];

int main ()
{
    freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,n,x,y,sum;
    cin>>t;
    while(t--){
        sum=0;
        cin>>n;
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum%3==0){
            int s=sum/3;
            int s1,s2,s3;
            s1=s2=s3=0;
            int i;
            int cnt=0;
            for(i=1;i<=n;++i){
                s1+=a[i];
                if(s1==s){
                    x=i;
                    i++;
                    cnt++;
                    break;
                }
            }
            for(i;i<=n;i++){
                s2+=a[i];
                if(s2==s){
                    y=i;
                    i++;
                    cnt++;
                    break;
                }
            }
            for(i;i<=n;i++){
                s3+=a[i];
                if(s3==s){
                    cnt++;
                    break;
                }
            }
            if(cnt==3)
                printf("%d %d\n",x,y);
            else
            printf("-1\n");
        }
        else
            printf("-1\n");
    }


	return 0;
}
