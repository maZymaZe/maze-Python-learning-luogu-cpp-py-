class Solution {
   public:
    int subtractProductAndSum(int n) {
        vector<int> t;
        while (n) {
            t.push_back(n % 10);
            n /= 10;
        }
        int a = 1, b = 0;
        for (int i : t)
            a *= i, b += i;
        return a - b;
    }
};