class Solution {
   public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        int l = target.size();
        for (int i = 0; i < l; i++) {
            mp[target[i]] = i;
        }
        vector<int> hv;
        int ll = arr.size();
        for (int i = 0; i < ll; i++) {
            if (mp.count(arr[i])) {
                hv.push_back(mp[arr[i]]);
            }
        }
        ll = hv.size();
        vector<int> ul;
        for (int i = 0; i < ll; i++) {
            if (ul.size() == 0 || hv[i] > ul.back()) {
                ul.push_back(hv[i]);
            } else {
                auto it = lower_bound(ul.begin(), ul.end(), hv[i]);
                *it = hv[i];
            }
        }
        return l - ul.size();
    }
};