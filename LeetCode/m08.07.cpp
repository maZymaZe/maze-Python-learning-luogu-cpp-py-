class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> ans;
        sort(S.begin(),S.end());
        do{
            ans.push_back(S);
        }while(next_permutation(S.begin(),S.end()));
        return ans;
    }
};