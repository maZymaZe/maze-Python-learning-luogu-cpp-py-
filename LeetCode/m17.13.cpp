class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        unordered_set<string> dic;
        for(auto i:dictionary)dic.insert(i);
        int l=sentence.size();
        vector<int> dp(l+1);
        dp[0]=0;
        for(int i=1;i<=l;i++){
            dp[i]=dp[i-1]+1;
            for(int j=1;j<=i;j++){
                if(dic.count(sentence.substr(j-1,i-j+1))){
                    dp[i]=min(dp[i],dp[j-1]);
                }
            }
        }
        return dp[l];
    }
};