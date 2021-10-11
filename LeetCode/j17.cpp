class Solution {
   public:
    vector<int> printNumbers(int n) {
        int lim = pow(10, n);
        vector<int> x;
        for (int i = 1; i < lim; i++)
            x.push_back(i);
        return x;
    }
};