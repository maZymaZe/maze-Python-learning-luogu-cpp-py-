class Solution {
   public:
    bool isBalanced(string num) {
        int l = num.size(), c[2] = {0};
        for (int i = 0; i < l; i++) {
            c[i & 1] += num[i] - '0';
        }
        return c[0] == c[1];
    }
};