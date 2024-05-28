class Solution {
   public:
    vector<int> findPeaks(vector<int>& mountain) {
        int l = mountain.size();
        vector<int> ans;
        for (int i = 1; i < l - 1; i++) {
            if (mountain[i] > mountain[i + 1] && mountain[i] > mountain[i - 1])
                ans.push_back(i);
        }
        return ans;
    }
};