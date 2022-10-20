class Solution {
   public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        for (auto& v : trips) {
            m[v[1]] += v[0];
            m[v[2]] -= v[0];
        }
        int tot = 0;
        for (auto it : m) {
            tot += it.second;
            if (tot > capacity)
                return false;
        }
        return true;
    }
};