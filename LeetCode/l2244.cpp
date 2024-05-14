class Solution {
   public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> x;
        int ans = 0;
        for (int i : tasks)
            x[i]++;
        for (int i : tasks) {
            if (x[i] == 1)
                return -1;
            ans += (x[i] + 2) / 3;
            x[i] = 0;
        }
        return ans;
    }
};