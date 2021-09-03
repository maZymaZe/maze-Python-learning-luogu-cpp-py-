class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<long long> s;
        long long w = n;
        int t;
        while (w != 1) {
            long long q = 0;
            while (w)
                t = w % 10, q += t * t, w /= 10;
            w = q;
            if (s.count(w))
                return false;
            s.insert(w);
        }
        return true;
    }
};