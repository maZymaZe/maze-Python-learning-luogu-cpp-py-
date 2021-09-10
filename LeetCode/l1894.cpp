class Solution {
   public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long tot = 0;
        for (int i : chalk)
            tot += i;
        k %= tot;
        int l = chalk.size();
        for (int i = 0; i < l; i++) {
            if (k < chalk[i])
                return i;
            k -= chalk[i];
        }
        return -1;
    }
};