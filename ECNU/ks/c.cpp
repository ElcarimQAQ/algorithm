#include <bits/stdc++.h>
using namespace std;
string str;

char a[3]={'A','O'};
char b[3]={'B','O'};
char ab[3]={'A','B'};
char o[3] = {'O'};

vector <char> s1,s2;

void slove(string x){
    if(x == "A"){
        for(int i = 0;i <= 2 ;i++){
            s1.push_back(a[i]);
        }
    }
    if(x == "B"){
        for(int i = 0;i <= 1 ;i++){
            s1.push_back(b[i]);
        }
    }
    if(x == "AB"){
        for(int i = 0;i <= 2 ;i++){
            s1.push_back(ab[i]);
        }
    }
    if(x == "O")
         s1.push_back('O');
}
void slove2(string x){
    if(x == "A"){
        for(int i = 0;i <= 2 ;i++){
            s2.push_back(a[i]);
        }
    }
    if(x == "B"){
        for(int i = 0;i <= 1 ;i++){
            s2.push_back(b[i]);
        }
    }
    if(x == "AB"){
        for(int i = 0;i <= 2 ;i++){
            s2.push_back(ab[i]);
        }
    }
    if(x == "O")
         s2.push_back('O');
}

vector<string> ans;

int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    if(c == "O"){
        if(a == "AB" || b == "AB")
            cout<<"AB impossible O"<<endl;
    }
    if(c == "?"){
        slove(a);
        slove2(b);
        for(auto a:s1){
            for(auto b :s2){
                string an = "";
                an += a;
                an += b;
                cout<<an<<endl;
                if(an == "AA")
                    ans.push_back("A");
                if(an == "OO")
                    ans.push_back("O");
                if(an == "BB")
                    ans.push_back("B");
                if(an == "AB")
                    ans.push_back("AB");
                
            }
        }
        cout<<a<<ans<<endl;
    }
    return 0;


}