class Solution {
   public:
    int dietPlanPerformance(vector<int>& calories,
                            int k,
                            int lower,
                            int upper) {
        int l = calories.size();
        if (l < k)
            return 0;
        int tot = 0;
        for (int i = 0; i < k; i++) {
            tot += calories[i];
        }
        int mk = 0;
        if (tot < lower)
            mk--;
        if (tot > upper)
            mk++;
        for (int i = k; i < l; i++) {
            tot += calories[i];
            tot -= calories[i - k];
            if (tot < lower)
                mk--;
            if (tot > upper)
                mk++;
        }
        return mk;
    }
};