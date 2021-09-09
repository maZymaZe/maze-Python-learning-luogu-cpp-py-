class Solution {
   public:
    int lengthLongestPath(string input) {
        input.push_back('\n');
        int level[100] = {0}, hf = 0;
        int len = 0, crl = 0, ans = 0;
        for (char c : input) {
            if (c == '\t')
                ++crl;
            else if (c == '\n') {
                level[crl] = len;
                if (hf) {
                    int mxl = 0;
                    for (int i = 0; i <= crl; i++) {
                        mxl += level[i];
                    }
                    ans = max(ans, mxl + crl);
                }
                crl = 0;
                len = 0;
                hf = false;
            } else {
                if (c == '.')
                    hf = 1;
                ++len;
            }
        }
        return ans;
    }
};