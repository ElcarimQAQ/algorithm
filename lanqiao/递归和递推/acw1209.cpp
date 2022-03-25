#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[10] = {1,2,3,4,5,6,7,8,9};
int n;

int  cal(int l,int r){
    int res = 0;
    while(l < r){
        res = res *10 + num[l];
        l++;
    }
    return res;
}

int main()
{
    cin>>n;
    int ans = 0;
    do{
        for(int i = 1;i < 9;i++){
            for(int j = i + 1;j < 9; j++) {
                int a,b,c;
                a = cal(0,i);
                b = cal(i,j);
                c = cal(j,9);
                // cout<<a<<" "<<b<<" "<<c<<endl;
                if(b % c == 0){
                    if(n == a  + b / c)
                        ans++;
                }
            }
        }
    }while(next_permutation(num,num + 9));
    cout<<ans<<endl;
    return 0;
}