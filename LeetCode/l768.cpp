class Solution {
   public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> t = arr;
        int n = t.size(), dif = 0, ans = 0;
        unordered_map<int, int> mp;
        sort(t.begin(), t.end());
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
            int p = mp[arr[i]];
            if (p == 1)
                dif++;
            if (p == 0)
                dif--;
            mp[t[i]]--;
            p = mp[t[i]];
            if (p == -1)
                dif++;
            if (p == 0)
                dif--;
            if (dif == 0)
                ans++;
        }
        return ans;
    }
};