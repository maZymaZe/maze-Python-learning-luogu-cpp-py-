class Solution {
   public:
    vector<string> permutation(string S) {
        sort(S.begin(), S.end());
        vector<string> ans;
        ans.push_back(S);
        while (next_permutation(S.begin(), S.end())) {
            ans.push_back(S);
        }
        return ans;
    }
};