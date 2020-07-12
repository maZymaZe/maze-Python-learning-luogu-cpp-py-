class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        vector<int> dpnow(m);
        if(dungeon[n-1][m-1]>=0)dpnow[m-1]=1;
        else dpnow[m-1]=-dungeon[n-1][m-1]+1;
        for(int i=m-2;i>=0;i--){
            dpnow[i]=max(1,dpnow[i+1]-dungeon[n-1][i]);
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(j==m-1){
                    dpnow[j]=max(1,dpnow[j]-dungeon[i][j]);
                }
                else{
                    dpnow[j]=max(1,min(dpnow[j],dpnow[j+1])-dungeon[i][j]);
                }
            }
        }
        return dpnow[0];

    }
};