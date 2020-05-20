class Solution {
public:
    int findTheLongestSubstring(string s) {
        int l=s.size(),ans=0,sta=0;
        vector<int> pos(1<<5,-1);
        pos[0]=0;
        char c[5]={'a','e','i','o','u'};
        for(int i=0;i<l;i++){
            
            for(int j=0;j<5;j++){
                if(s[i]==c[j])sta^=(1<<j);
            }
            if(~pos[sta])ans=max(ans,i+1-pos[sta]);
            else pos[sta]=i+1;
        }
        return ans;
    }
};