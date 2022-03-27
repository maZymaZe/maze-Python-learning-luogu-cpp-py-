class Solution {
   public:
    bool hasAlternatingBits(int n) {
        vector<int> x;
        while (n)
            x.push_back(n % 2), n /= 2;
        int p = x[0], l = x.size();
        for (int i = 1; i < l; i++)
            if (x[i] == p)
                return false;
            else
                p ^= 1;
        return true;
    }
};