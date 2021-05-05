class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans(1,first);
        for(auto &i:encoded)ans.push_back(i^ans.back());
        return ans;
    }
};