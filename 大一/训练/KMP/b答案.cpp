#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 +100;
int n, m;
int P[10100];
int S[N];
void GetNextval(int *P, int nextval[])
{
    int p_len = m;
    int i = 0;   // P 的下标
    int j = -1;
    nextval[0] = -1;
 
    while (i < p_len)
    {
        if (j == -1 || P[i] == P[j])
        {
            i++;
            j++;
 
            if (P[i] != P[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];  // 既然相同就继续往前找真前缀
        }
        else
            j = nextval[j];
    }
}
int KMP(int *S, int *P, int next[])
{
    GetNextval(P, next);
 
    int i = 0;  // S 的下标
    int j = 0;  // P 的下标
    int s_len = n;
    int p_len = m;
 
    while (i < s_len && j < p_len)
    {
        if (j == -1 || S[i] == P[j])  // P 的第一个字符不匹配或 S[i] == P[j]
        {
            i++;
            j++;
        }
        else
            j = next[j];  // 当前字符匹配失败，进行跳转
    }
 
    if (j == p_len)  // 匹配成功
        return i - j + 1;
 
    return -1;
}
int main(){
    int next[10100];
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n - 1; i++){
            scanf("%d", &S[i]);
        }
        for(int i = 0; i <= m - 1; i++){
            scanf("%d", &P[i]);
        }
//        int x = KMP(S, P, next);
        if(n < m)printf("-1\n");
        else printf("%d\n", KMP(S, P, next));
    }
    return 0;
}

