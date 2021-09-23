class Solution {
   public:
    int findComplement(int num) {
        vector<int> d;
        while (num) {
            d.push_back(num & 1);
            num >>= 1;
        }
        int ans = 0, l = d.size();
        for (int i = l - 1; i >= 0; i--) {
            ans <<= 1;
            ans |= (d[i] ^ 1);
        }
        return ans;
    }
};