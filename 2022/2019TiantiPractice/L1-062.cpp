#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    string str;
    cin>>n;
    while(n--) {
        cin>>str;
        int f = 0,b = 0;
        for(int i = 0;i <3; i++)
            f +=  str[i] - '0';
        for(int i = 3;i < 6; i++)
            b += str[i] - '0';
        if(f == b) puts("You are lucky!");
        else puts("Wish you good luck.");
    }
    return 0;
}