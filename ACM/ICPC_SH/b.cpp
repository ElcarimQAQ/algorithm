#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1[1005],s2[1005];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++) 
        cin>>s1[i];
    for(int i=0;i<n;i++) 
        cin>>s2[i];  
    int cnt1,cnt2;
    cnt1 =cnt2=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s2[i][j]!=s1[i][j]) cnt1++;
            if(s2[i][j]==s1[i][j])
                cnt2++;
        }
    }
    if(cnt1<=(m*n)/2) {
        for(int i = 0;i<n;i++)
            cout<<s1[i]<<endl;
    }
    else if(cnt2<=(m*n)/2){
        for(int i = 0;i<n;i++){
            for(int j = 0 ;j < m;j++){
                if(s1[i][j] == 'X')
                    cout<<".";
                else
                    cout<<"X";
            }
            cout<<endl;       
        }
    }
    else
    {
        cout<<-1<<endl;
    }
    system("pause");
    return 0;
}