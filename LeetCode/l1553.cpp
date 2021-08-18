class Solution {
   public:
    unordered_map<int, int> mp;
    int minDays(int n) {
        if (n <= 1)
            return n;
        if (mp.count(n))
            return mp[n];
        return mp[n] =
                   min(n % 2 + 1 + minDays(n / 2), n % 3 + 1 + minDays(n / 3));
    }
};