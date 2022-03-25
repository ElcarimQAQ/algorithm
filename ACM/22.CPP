#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param charList char字符型vector 上述C字符集合，集合大小不大于10，不重复
     * @param s string字符串 上述字符串s，长度不大于100000
     * @return int整型
     */
    map<char,int> mp;
    int  vis[100005][15];
    int L;
    int check(int x)
    {
        int l = 0,r = l + x - 1;
        while(r < L){
            int f = 1; 
            for(int i = 0;i < mp.size(); i++){
                if(l == 0){
                    if(vis[r][i] % 2 != 0)
                    {f = 0;break;}
                }
                else {
                    if((vis[r][i] - vis[l - 1][i]) % 2 != 0){
                        f = 0;break;
                    }
                }
            }
            if(f == 0)
                l++;
            else
                return 0;
            r = l + x - 1;
        }
        return 1;
    }
    int maxSubStrLength(vector<char>& charList, string s) {
        // write code here
        L = s.size();
        for(int i =0; i < charList.s        ize();++i)
            mp[charList[i]] = i;
        for(int i = 0;i < s.size(); ++i){
            int j ;
            if(i != 0){
                for(int j = 0;j <charList.size(); ++j)
                    vis[i][j] = vis[i - 1][j];
            }
            if(mp.find(s[i]) != mp.end()){
                j= mp[s[i]];
                vis[i][j]++; 
            }
        }
        int l = 0,r = 100000;
        while(l < r){
            int m = (l + r) >> 1;
            if(check(m)) r = m;
            else
                l = m + 1;
        }
        return l;
    }
};

int main()
{
    Solution s;
    vector<char> ch;
    ch.push_back('a');
    ch.push_back('b');
    ch.push_back('C');
    string str="axabybbbC";
    cout<<s.maxSubStrLength(ch,str);
    return 0;
}