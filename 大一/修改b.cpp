#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include<algorithm>
using namespace std;
string s,ans;
int main ()
{
    cin>>s;
    getchar();
    int cont=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='1')
            cont++;
        if (s[i]=='0')
            ans+='0';
        if (s[i]=='2')
            ans+='2';
    }
    int f=0;
    for (int i=0;i<ans.size();i++){
        if (ans[i]=='2'&&f==0){
            f=1;
            cout<<string(cont,'1');
            }
        cout<<ans[i];

    }
    if (f==0)
        cout<<string(cont,'1');
	return 0;
}

