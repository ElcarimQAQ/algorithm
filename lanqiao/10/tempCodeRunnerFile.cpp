#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> ha;
int main()
{
    int n,x;
    char c;
    cin>>n;
    while(n--){
        cin>>c>>x;
        if(c == 'I') ha[x]++;
        if(c == 'Q') {
            if(ha.find(x) != ha.end())
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }

    }
    
    return 0;
}