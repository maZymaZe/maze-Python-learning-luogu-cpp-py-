class Solution {
   public:
    int countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
        int l = hours.size();
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                if ((hours[i] + hours[j]) % 24 == 0)
                    ans++;
            }
        }
        return ans;
    }
};