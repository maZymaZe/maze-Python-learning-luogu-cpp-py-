class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int l=strs.size(),len=strs[0].size(),ans=0;
        if(l==1)return 0;
        for(int i=1;i<l;i++){
            for(int j=0;j<len;j++){
                if(strs[i][j]<strs[i-1][j])strs[0][j]='1';
            }
        }
        for(int i=0;i<len;i++){
            if(strs[0][i]=='1')ans++;
        }
        return ans;
    }
};