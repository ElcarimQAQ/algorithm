#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
const int N =  1000010;

string e[N];
int idx;
bool fa = false;
int f[N], path[N];

void dfs(int u)
{
	if(u == 0) return;
	dfs(path[u]);
	cout<< e[u];
}

int main()
{
	string s, t; cin >> s;
	//处理输入的字符串，把每个名字存入字符串数组中 
	for(int i = 0; i < s.size(); i ++ )
	{
		if(s[i] >= 'A' && s[i] <= 'Z' )
		{
			if(!fa) 
				t += s[i];
			else
			{
				e[idx ++] = t;
				t = "";
				t += s[i];
				fa = false;
			}
			fa = true;
		}
		else t += s[i];
		if(i == s.size() - 1) e[idx ++] = t;
	}
	
	// dp 求最大上升子序列 
	int maxx = -1, pos;
	for(int i = 0; i < idx; i ++ )
	{
		f[i] = 1;
		for(int j = 0;j < i;j ++ )
		{
			if(e[j] < e[i]) 
			{
				f[i] = max(f[i], f[j] + 1);
				path[i] = j;
				if(maxx < f[i])
				{
					//记录位置 
					maxx = f[i];
					pos = i;
				}
			}	
		}
	} 
	
//	for(int i = 0 ;i < 100; i ++ )
//		if(path[i] != 0) cout << "i == " << i << " " << path[i] << endl;  
//	cout << "pos :" << pos << endl;
	// 遍历最大上升子序列 
	dfs(pos);
	
	return 0; 
}
