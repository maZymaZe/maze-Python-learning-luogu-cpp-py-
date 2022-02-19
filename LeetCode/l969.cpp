class Solution {
   public:
    vector<int> pancakeSort(vector<int>& arr) {
        int l = arr.size();
        vector<int> ans;
        for (int i = l - 1; i >= 0; i--) {
            if (arr[i] == i + 1)
                continue;
            int p = 0;
            while (arr[p] != i + 1)
                p++;
            if (p) {
                reverse(arr.begin(), arr.begin() + p + 1);
                ans.push_back(p + 1);
            }
            if (i) {
                reverse(arr.begin(), arr.begin() + i + 1);
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};