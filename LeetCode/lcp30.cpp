class Solution {
   public:
    int magicTower(vector<int>& nums) {
        long long blood = 1, td = 0, ans = 0, sum = 0;
        int l = nums.size();
        for (int i = 0; i < l; i++)
            blood += nums[i];
        if (blood <= 0)
            return -1;
        blood = 1;

        priority_queue<long long> pq;
        for (int i = 0; i < l; i++) {
            if (nums[i] < 0)
                pq.push(-nums[i]);
            blood += nums[i];
            while (blood <= 0) {
                int c = pq.top();
                pq.pop();
                blood += c;
                ans++;
            }
        }

        return ans;
    }
};