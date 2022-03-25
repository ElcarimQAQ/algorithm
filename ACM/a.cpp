#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 输入多个城市之间的距离，返回到其他城市最近的城市的标号，如果无法从这几个城市之间选出满足条件的城市，那么返回-1。
     * @param distancePairs int整型vector<vector<>> 二维数组，每个子数组都是三个整数组成的，前两个整数代表城市的标号，第三个整数代表两个城市的距离
     * @param CityNum int整型 城市的数量，每个城市的标号分别是0~CityNum-1
     * @return int整型
     */
    vector<pair<int,int> > g[105];
    int vis[105],dis[105];
    int dij(int s){
        for(int i =0;i < g[s].size(); ++i){
            int v = g[s][i].first;
            dis[v] = min(dis[v],s + g[s][i].second);

        }
    }
    int GetBestWarehouseLocate(vector<vector<int> >& distancePairs, int CityNum) {
        // write code here
        for(int i = 0;i < distancePairs.size();++i){
            int u = distancePairs[i][0];
            int v = distancePairs[i][1];
            int w = distancePairs[i][2];
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        for(int i = 0;i <CityNum; ++i){
            memset(vis,0,sizeof(vis));
            dij(s);

        }
    }
};