class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size(),ans=0;
        vector<int> tmp(n);
        for(int i=0; i<n; i++)tmp[row[i]]=i;
        for(int i=0;i<n;i+=2){
            if(row[i]^row[i+1]^1){
                ans++;
                int t=tmp[row[i]^1];
                tmp[row[i+1]]=t;
                row[t]=row[i+1];
            }
        }
        return ans;
    }
};