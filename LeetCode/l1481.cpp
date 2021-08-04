class Solution {
   public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto i : arr) {
            mp[i]++;
        }
        vector<int> v;
        for (auto i : mp)
            v.push_back(i.second);
        sort(v.begin(), v.end());
        int c = v.size();
        int l = v.size();
        for (int i = 0; i < l; i++) {
            if (k >= v[i]) {
                k -= v[i];
                c--;
            } else
                break;
        }
        return c;
    }
};