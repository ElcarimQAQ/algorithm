#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;

struct  stu
{
    string name,sex,id;
    int grade;
    stu(){}
    stu(string a,string b,string c,int d):name(a),sex(b),id(c),grade(d){}
};

vector<stu>girl,boy;
int main()
{
    int n;
    cin>>n;
    int cntM,cntF;
    cntM = cntF = 0;
    string name,sex,id;
    int gra;
    int ma = 0;
    int mi = 100;
    stu maxG,minB;
    while(n--){
        cin>>name>>sex>>id>>gra;
        if(sex == "F"){
            cntF++;
            if(gra > ma|| ma == 0){
                ma = max(ma,gra);
                maxG = stu(name,sex,id,gra);
            }
            
        }
        else {
            cntM++;
            if(gra < mi || mi == 100){
                mi = min(mi,gra);
                minB = stu(name,sex,id,gra);
            }
        }
    }
    if(cntF == 0 ) cout<<"Absent"<<endl;
    else cout<<maxG.name<<" "<<maxG.id<<endl;
    if(cntM == 0) cout<<"Absent"<<endl;
    else cout<<minB.name<<" "<<minB.id<<endl;
    if(cntF  == 0|| cntM == 0){
        cout<<"NA"<<endl;
    }
    else cout<<ma - mi<<endl;
    return 0;
}