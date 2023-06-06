class Solution {
   public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans = 0, l = reward2.size();
        for (int i = 0; i < l; i++) {
            ans += reward2[i];
            reward1[i] -= reward2[i];
        }
        nth_element(reward1.begin(), reward1.begin() + k, reward1.end(),
                    greater<int>());
        for (int i = 0; i < k; i++) {
            ans += reward1[i];
        }
        return ans;
    }
};