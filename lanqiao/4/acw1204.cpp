#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int a[maxn];

int main()
{
    int n,l,ans1,ans2;
    cin>>n;
    string s;   
    getline(cin,s);
    l = 0;
    while(n--){
        getline(cin,s);
        stringstream ss(s);
        while(ss >> a[l]) l++;
    }
    sort(a,a+l);
    for(int i = 1; i <= l; i++){
        if(a[i] == a[i - 1])
            ans2 = a[i];
        if(a[i] == a[i - 1] + 2)
            ans1 = a[i] - 1; 
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}