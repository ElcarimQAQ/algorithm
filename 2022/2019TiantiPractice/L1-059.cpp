#include <bits/stdc++.h>
using namespace std;
vector<string> ans;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string str;
    getline(cin, str);
    while(n--) {
        string word;
        ans.clear();
        getline(cin, str);
        stringstream ss;
        ss << str;
        bool flag = true;
        while(ss >> word){
            if(!flag) continue;
            int la = word.size() - 1;
            if(word[la] != ',' && word[la] != '.') {
                ans.push_back(word);
                continue;
            }

            if(word.length() >= 4 && ( word[la - 3] == 'o' || word[la - 3] == 'O' )&& ( word[la - 2] == 'n' || word[la - 2] == 'N') && (word[la - 1] == 'g' || word[la - 1] == 'G')) {
                if(word[la] == ',') ans.push_back(word);
                else {
                    for(int i = 0; i< ans.size() - 2; i++)
                        cout<<ans[i]<<" ";
                    cout<<"qiao ben zhong."<<endl;
                }
            } else {
                flag = false;
                cout<<"Skipped"<<endl;
                //break;
            }
        }
    }
    return 0;
}