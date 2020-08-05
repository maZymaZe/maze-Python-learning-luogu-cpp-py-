class Solution {
public:
    char findTheDifference(string s, string t) {
        int l1=s.size(),ans=0;
        for(int i=0;i<l1;i++)ans-=s[i];
        for(int i=0;i<=l1;i++)ans+=t[i];
        return ans;
    }
};