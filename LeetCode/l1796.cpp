class Solution {
   public:
    int secondHighest(string s) {
        int a[10] = {0};
        for (auto c : s) {
            if (isdigit(c))
                a[c - '0']++;
        }
        int f = 0;
        for (int i = 9; i >= 0; i--) {
            if (a[i]) {
                if (f)
                    return i;
                else
                    f = 1;
            }
        }
        return -1;
    }
};