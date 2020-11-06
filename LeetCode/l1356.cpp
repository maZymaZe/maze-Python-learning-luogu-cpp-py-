struct pr {
    int a, b;
    bool operator<(const pr& x) {
        if (b < x.b)
            return true;
        if (b == x.b)
            return a < x.a;
        return false;
    }
};
class Solution {
   public:
    vector<int> sortByBits(vector<int>& arr) {
        int l = arr.size();
        vector<pr> v(l);
        for (int i = 0; i < l; i++) {
            v[i].a = arr[i];
            int t = arr[i], c = 0;
            while (t) {
                t -= (-t) & t;
                c++;
            }
            v[i].b = c;
        }
        sort(v.begin(), v.end());
        vector<int> ans(l);
        for (int i = 0; i < l; i++)
            ans[i] = v[i].a;
        return ans;
    }
};