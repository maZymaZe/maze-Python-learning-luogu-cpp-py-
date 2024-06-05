struct TA {
    vector<int> arr;
    int lim;
    TA(int sz) {
        lim = 2 * sz;
        arr.resize(lim + 1);
    }
    void add1(int x) {
        while (x <= lim) {
            arr[x]++;
            x += ((-x) & x);
        }
    }
    int _query(int x) {
        int ans = 0;
        while (x) {
            ans += arr[x];
            x -= ((-x) & x);
        }
        return ans;
    }
    int query(int x) { return _query(lim) - _query(x); }
};
class Solution {
   public:
    vector<int> resultArray(vector<int>& nums) {
        auto m = nums;
        sort(m.begin(), m.end());
        auto ue = unique(m.begin(), m.end());
        int sz = ue - m.begin();
        unordered_map<int, int> mp;
        for (int i = 0; i < sz; i++)
            mp[m[i]] = i + 1;
        vector<int> v1, v2;
        TA t1(sz), t2(sz);
        int l = nums.size();
        t1.add1(mp[nums[0]]);
        t2.add1(mp[nums[1]]);
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        for (int i = 2; i < l; i++) {
            int tg = 0, tn = mp[nums[i]];
            int q1 = t1.query(tn), q2 = t2.query(tn);
            if (q1 > q2) {
                tg = 1;
            } else if (q2 > q1) {
                tg = 2;
            } else if (v1.size() > v2.size()) {
                tg = 2;
            } else
                tg = 1;
            if (tg == 1) {
                t1.add1(tn);
                v1.push_back(nums[i]);
            } else {
                t2.add1(tn);
                v2.push_back(nums[i]);
            }
        }
        vector<int> ans;
        for (int i : v1)
            ans.push_back(i);
        for (int i : v2)
            ans.push_back(i);
        return ans;
    }
};