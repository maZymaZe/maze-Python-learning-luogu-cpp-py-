class Solution {
   public:
    void sf(int l, int r, vector<int>& x) {
        vector<int> t;
        for (int i = l + 1; i <= r; i += 2)
            t.push_back(x[i]);
        for (int i = l; i <= r; i += 2)
            t.push_back(x[i]);
        for (int i = l; i <= r; i++)
            x[i] = t[i - l];
    }
    bool isMagic(vector<int>& target) {
        int n = target.size();
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }
        sf(0, n - 1, v);
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (target[i] == v[i])
                k++;
            else
                break;
        }
        if (k == 0)
            return false;
        for (int i = k; i < n; i += k) {
            sf(i, n - 1, v);
        }
        for (int i = 0; i < n; i++)
            if (v[i] != target[i])
                return false;
        return true;
    }
};