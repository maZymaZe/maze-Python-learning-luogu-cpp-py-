class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dis(n,0x3f3f3f3f),dis2(n);
        dis[src] = 0;
        for(int i=0;i<=K;i++){
            for(int j=0;j<n;j++){dis2[j]=-1;}
            for(auto &f:flights){
                if(dis[f[1]]>dis[f[0]]+f[2]){
                    if(dis2[f[1]]!=-1)dis2[f[1]]=min(dis[f[0]]+f[2],dis2[f[1]]);
                    else dis2[f[1]]=dis[f[0]]+f[2];
                }
            }
            for(int j=0;j<n;j++)if(dis2[j]!=-1)dis[j]=dis2[j];
        }
        if(dis[dst]==0x3f3f3f3f)return -1;
        return dis[dst];
    }
};