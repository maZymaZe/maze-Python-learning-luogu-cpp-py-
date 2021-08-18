class Solution {
   public:
    int findNumbers(vector<int>& nums) {
        int ans = 0, c = 0, t = 0;
        for (auto i : nums) {
            t = i;
            c = 0;
            while (t) {
                c++;
                t /= 10;
            }
            if ((c & 1) == 0)
                ans++;
        }
        return ans;
    }
};