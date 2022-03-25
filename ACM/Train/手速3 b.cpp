#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;
typedef long long ll;


int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    string s;
    int n;
    cin>>n;
    cin>>s;
    int cnt=0;
    while(s.find("xxx")!=-1){
        int i=s.find("xxx");
        s=s.erase(i,1);
        cnt++;
    }
    printf("%d\n",cnt);
	return 0;
}

