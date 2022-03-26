class Solution {
   public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int tot = (rolls.size() + n) * mean;
        for (int i : rolls) {
            tot -= i;
        }
        vector<int> result(n, tot / n);
        if (tot / n <= 0 || tot / n > 6)
            return {};
        if (tot / n == 6 && tot % n != 0)
            return {};
        tot %= n;

        for (int i = 0; i < tot; i++)
            result[i]++;
        return result;
    }
};