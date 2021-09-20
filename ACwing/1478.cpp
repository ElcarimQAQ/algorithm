#include <bits/stdc++.h>
using namespace std;


struct T
{
    int hh,mm,ss;
    T():hh(),mm(),ss(){}
    T(int x,int y,int z):hh(x),mm(y),ss(z){}
};


struct stu{
    string ID;
    string st,ed;
}st[105];

bool cmp1(stu a,stu b){
    return a.st < b.st;
}

bool cmp2(stu a,stu b){
    return a.ed > b.ed;
}

int main()
{
    int m;
    cin>>m;
    for(int i = 0;i < m; i++){
        cin>>st[i].ID>>st[i].st>>st[i].ed;
    }
    sort(st,st+m,cmp1);
    cout<<st[0].ID<<" ";
    sort(st,st+m,cmp2);
    cout<<st[0].ID<<endl;

}

