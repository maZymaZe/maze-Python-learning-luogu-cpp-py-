class Solution {
   public:
    bool checkString(string s) {
        int f = 0;
        for (char c : s) {
            if (c == 'b')
                f = 1;
            else if (f)
                return false;
        }
        return true;
    }
};