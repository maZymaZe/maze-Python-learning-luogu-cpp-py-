class Solution {
   public:
    int bitwiseComplement(int N) {
        if (N == 0)
            return 1;
        vector<int> d;
        while (N) {
            d.push_back(N & 1);
            N >>= 1;
        }
        int ans = 0, l = d.size();
        for (int i = l - 1; i >= 0; i--) {
            ans <<= 1;
            ans |= (d[i] ^ 1);
        }
        return ans;
    }
};