#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> PII;
int a[maxn];

int main()
{   
    int n,s;
    cin>>n>>s;
    int sum = 0;
    double avg;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sum += a[i];
    }
    avg = sum * 1.0 / n;
    
    return 0;
}