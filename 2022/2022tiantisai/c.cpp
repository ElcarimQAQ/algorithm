#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d; 
    int s,sp,e,ep;
    int f = 1;
    if(c < d){
        s = c;
        e = d;
        sp = 1;
        ep = 2;
    }else {
        s = d;
        e = c;
        sp = 2;
        ep = 1;
        f = 0;
    }
    if(s >= a && e >= a) {
        if(f) printf("%d-Y %d-Y\n",s,e);
        else printf("%d-Y %d-Y\n",e,s);
        cout<<"huan ying ru guan"<<endl;
    }else if(s < a && e >=b ) {
        if(f) printf("%d-Y %d-Y\n",s,e);
        else printf("%d-Y %d-Y\n",e,s);
        printf("qing %d zhao gu hao %d\n",ep, sp);
    }else if(s < a && e < a ) {
        if(f) printf("%d-N %d-N\n",s,e);
        else printf("%d-N %d-N\n",e,s);
        printf("zhang da zai lai ba\n");
    }
    else if(s < a && e < b) {
        if(f) printf("%d-N %d-Y\n",s,e);
        else printf("%d-Y %d-N\n",e,s);
        printf("%d: huan ying ru guan\n",ep);
    }
    return 0;
}