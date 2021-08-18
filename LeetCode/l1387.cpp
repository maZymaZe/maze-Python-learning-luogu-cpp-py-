class Solution {
   public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> v;
        for (int i = lo; i <= hi; i++) {
            int t = i, c = 0;
            while (t != 1) {
                if (t & 1)
                    t = t * 3 + 1;
                else
                    t >>= 1;
                c++;
            }
            v.push_back(make_pair(c, i));
        }
        sort(v.begin(), v.end(), cmp);
        return v[k - 1].second;
    }
};