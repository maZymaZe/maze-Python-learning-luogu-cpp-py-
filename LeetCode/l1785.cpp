class Solution {
   public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long dis = 0;
        for (auto it : nums)
            dis += it;
        dis -= goal;
        dis = abs(dis);
        return (dis + limit - 1) / limit;
    }
};