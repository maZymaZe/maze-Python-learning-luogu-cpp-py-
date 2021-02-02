class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> num(26);
        int n=s.length();
        int maxn=0;
        int l=0,r=0;
        while(r<n){
            num[s[r]-'A']++;
            maxn=max(maxn,num[s[r]-'A']);
            if(r-l+1-maxn>k)num[s[l]-'A']--,l++;
            r++;
        }
        return r-l;
    }
};