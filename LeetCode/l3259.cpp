class Solution {
   public:
    long long maxEnergyBoost(vector<int>& energyDrinkA,
                             vector<int>& energyDrinkB) {
        long long a[2] = {0}, b[2] = {0};
        int n = energyDrinkA.size();
        a[0] = energyDrinkA[0], b[0] = energyDrinkB[0];
        for (int i = 1; i < n; i++) {
            a[i & 1] = max(a[(i & 1) ^ 1] + energyDrinkA[i], b[(i & 1) ^ 1]);
            b[i & 1] = max(b[(i & 1) ^ 1] + energyDrinkB[i], a[(i & 1) ^ 1]);
        }
        return max(a[(n - 1) & 1], b[(n - 1) & 1]);
    }
};