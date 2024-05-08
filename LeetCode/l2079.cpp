class Solution {
   public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int l = plants.size(), t = capacity, p = 0, ans = 0;
        for (int i = 0; i < l; i++) {
            if (t >= plants[i]) {
                t -= plants[i];
                ans++;
            } else {
                t = capacity - plants[i];
                ans += (2 * i + 1);
            }
        }
        return ans;
    }
};