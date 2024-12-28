class Solution {
   public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
            if (mp[i] == 3)
                return false;
        }
        return true;
    }
};