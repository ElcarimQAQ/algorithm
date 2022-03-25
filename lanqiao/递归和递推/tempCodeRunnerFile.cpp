#include<bits/stdc++.h>
using namespace std;
string s1,s2;
void turn(int x)
{
    if(x < 0 || x >= s1.size()) return;
    if(s1[x] == '*')
        s1[x] = 'o';
    else s1[x] = '*';
}
int main()
{
    cin>>s1>>s2;
    int cnt=0;
    for(int i = 0;i < s1.size(); ++i){
        if(s1[i] !=s2[i]){
            turn(i + 1);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;

}