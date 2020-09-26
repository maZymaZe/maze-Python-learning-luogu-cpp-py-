class Solution {
public:
    int f[20002]={0},u[20002]={0},cnt=0,l;
    int ff(int x) {
        if (f[x] == x) return x;
        return f[x]=ff(f[x]);
    }
    int removeStones(vector<vector<int>>& stones) {
        for(int i=1;i<20001;i++)f[i]=i;
        l=stones.size();
        for(int i=0;i<l;i++){
            f[ff(stones[i][1]+10000)]=ff(stones[i][0]);
        }
        for(int i=0;i<l;i++){
            if(!u[ff(stones[i][0])]){
                cnt++;
                u[ff(stones[i][0])]=1;
            }
        }
        return l-cnt;
    }
};