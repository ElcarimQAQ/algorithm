#include <bits/stdc++.h>
using namespace std;

string eng[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"} ;

int main()
{
    string n;
    cin>>n;
    int sum = 0;
    for (int i =0;i < n.size();i++){
        sum += (n[i] -'0');
    }
    string strSum = to_string(sum);
    for(int i = 0;i < strSum.size(); i++){
        cout<<eng[strSum[i] - '0']<<" ";
    }
    return 0;
}

