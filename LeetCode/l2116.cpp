class Solution {
   public:
    bool canBeValid(string s, string locked) {
        int x = 0, y = 0;
        int l = locked.size();
        if (l & 1)
            return false;
        for (int i = 0; i < l; i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    x++, y++;
                } else {
                    x--, y--;
                    if (y < 0) {
                        return false;
                    }
                }
            } else {
                y++;
                x--;
            }
            if (x == -1) {
                x = 1;
            }
        }
        return x == 0;
    }
};