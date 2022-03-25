#include <bits/stdc++.h>
using namespace std;
const int maxn = 405;
 
int main()
{
    int t,a,b,n;
    cin>>t;
    string s;
    while(t--){
        int f = 1,suma = 0,sumb = 0;
        cin>>a>>b;
        cin>>s;
        n =s.size();
        for(int i = 0;i < n ; ++i){
            if(s[i] == '0') suma++;
            if(s[i] == '1') sumb++;
        }
        for(int i = 0;i < n ; ++i){
            if(s[i] == s[n - i - 1] )
                continue;            
            if(s[i] == '?'||s[n - i - 1] == '?'){
                if(s[n - i - 1] == '0'){
                    suma++;
                    s[i] = s[n - i -1];
                }
                if(s[n - i - 1] == '1'){
                    sumb++;             
                    s[i] = s[n - i -1];
                }       
                continue;
            }
            else{
                f =0;
                // cout<<-1<<endl;
                break;
            }
        }
        // cout<<suma<<" "<<sumb<<endl;
        if(suma > a||sumb > b) f = 0;
        if(f == 0){
            cout<<-1<<endl;
            continue;
        }
        suma = a - suma,sumb = b -sumb;
        // cout<<suma<<" "<<sumb<<endl;
        if((suma % 2) && (sumb % 2)){
            cout<<-1<<endl;
            continue;
        }
        int vis = 0;
        if(sumb % 2) vis = 1;
        for(int i = 0;i < (n+1) / 2;i++){
            if(s[i] == '?' && s[n - i - 1] == '?'){
                if(i == n -i -1){
                    if(!vis){
                        s[i] = '0';
                        suma--;
                    }
                    else{
                        s[i] = '1';
                        sumb--;
                    }
                    continue;
                }
                if(suma >= 2){
                    s[i] = '0';
                    s[n - i - 1] ='0';
                    suma -=2; 
                }
                else if(sumb >= 2){
                    s[i] = '1';
                    s[n - i - 1] ='1';
                    sumb -=2; 
                }
                else{
                    f = 0;
                    break;
                }
            }
        }
        if(f == 0){
            cout<<-1<<endl;
            continue;
        }
        cout<<s<<endl;
    }
    return 0;
}