class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            ans.push_back((long long)ans.back()*(rowIndex-i+1)/i);
        }
        return ans;
    }
};