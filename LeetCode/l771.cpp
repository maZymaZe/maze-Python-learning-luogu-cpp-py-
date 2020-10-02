class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int c[200]={0},ans=0;
        for(auto &i:J)c[i]=1;
        for(auto &i:S)ans+=c[i];
        return ans;
    }
};