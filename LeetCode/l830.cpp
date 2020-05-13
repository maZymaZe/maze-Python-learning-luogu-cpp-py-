class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        int b=0,l=S.size(),cnt;
        for(int i=0;i<l-1;i++){
            if(S[i]!=S[i+1]){
                if(i-b+1>=3){
                    vector<int> tmp(2,0);
                    tmp[0]=b,tmp[1]=i;
                    ans.push_back(tmp);
                }
                b=i+1;
            }
        }
        if(l-1-b+1>=3){
            vector<int> tmp(2,0);
            tmp[0]=b,tmp[1]=l-1;
            ans.push_back(tmp);
        }
        return ans;       
    }
};