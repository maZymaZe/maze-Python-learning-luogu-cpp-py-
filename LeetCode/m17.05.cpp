class Solution {
   public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int l = array.size();
        vector<int> tot(l + 1);
        for (int i = 0; i < l; i++) {
            if (array[i][0] >= '0' && array[i][0] <= '9')
                tot[i + 1] = tot[i] + 1;
            else
                tot[i + 1] = tot[i] - 1;
        }
        const int mxl = 1e6;
        int fs[2 * mxl + 1] = {0}, ls[2 * mxl + 1] = {0};
        for (int i = 1; i <= l; i++) {
            if (fs[tot[i] + mxl] == 0 && tot[i] != 0)
                fs[tot[i] + mxl] = i;
            ls[tot[i] + mxl] = i;
        }
        int ml = 1, pos = -1;
        for (int i = 0; i <= l; i++) {
            if (ls[tot[i] + mxl] - fs[tot[i] + mxl] > ml) {
                ml = ls[tot[i] + mxl] - fs[tot[i] + mxl];
                pos = fs[tot[i] + mxl];
            }
        }
        if (ml == 1)
            return {};
        vector<string> ans;
        for (int i = 0; i < ml; i++) {
            ans.push_back(array[pos + i]);
        }
        return ans;
    }
};