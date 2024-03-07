class Solution {
   public:
    vector<int> divisibilityArray(string word, int m) {
        int l=word.size();
        vector<int> ans(l);
        long long x=0;
        for(int i=0; i<l; i++){
            x=x*10+(word[i]-'0');
            x%=m;
            ans[i]=(!x);
        }
        return ans;
    }
};