class Solution {
   public:
    int sumOfUnique(vector<int>& nums) {
        int c[102] = {0}, ans = 0;
        for (int i : nums)
            c[i]++;
        for (int i = 0; i < 101; i++)
            if (c[i] == 1)
                ans += i;
        return ans;
    }
};