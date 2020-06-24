class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto i:wordDict)st.insert(i);
        int l=s.size();
        vector<bool> dp(l+1);
        dp[0]=true;
        for(int i=1;i<=l;i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&st.count(s.substr(j,i-j))){
                    dp[i]=true;break;
                }
            }
        }
        return dp[l];
    }
};