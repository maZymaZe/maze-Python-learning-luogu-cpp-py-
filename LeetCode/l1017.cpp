class Solution {
   public:
    string baseNeg2(int n) {
        if (!n)
            return "0";
        long long t = 2, p = 1, N = n;
        string ans;
        while (N != 0) {
            if (N % t) {
                ans.push_back('1');
                N -= p * t / 2;
            } else
                ans.push_back('0');
            t *= 2;
            p *= -1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};