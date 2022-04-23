#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int main()
{
    int n;
    int h1,h2,ne[maxn],st[maxn];
    char e[maxn];
    cin>>h1>>h2>>n;
    int ad,next;
    char data;
    for(int i = 0;i < n; i++) {
        cin>>ad>>data>>next;
        e[ad] = data;
        ne[ad] = next ;
    }
    for(int i = h1; i != -1 ;i = ne[i]){
        st[i] = 1;
    }
    for(int i = h2; i != -1 ;i = ne[i]){
        if(st[i] == 1) {
            printf("%05d\n",i);
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}