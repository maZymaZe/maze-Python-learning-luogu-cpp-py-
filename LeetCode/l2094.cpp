class Solution {
   public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        int vis[1000] = {0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)
                        continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num % 2 == 0 && num >= 100) {
                        vis[num] = 1;
                    }
                }
            }
        }
        vector<int> ans;
        for (int i = 100; i < 1000; i++) {
            if (vis[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};