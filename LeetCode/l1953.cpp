class Solution {
   public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long mx = 0, tot = 0;
        for (int i : milestones) {
            mx = max(mx, (long long)i);
            tot += i;
        }
        if (tot - mx >= mx - 1)
            return tot;
        return 2ll * (tot - mx) + 1;
    }
};