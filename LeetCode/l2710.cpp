class Solution {
   public:
    string removeTrailingZeros(string num) {
        int l = num.size();
        for (int i = l - 1; i >= 0; i--) {
            if (num[i] != '0')
                return num.substr(0, i + 1);
        }
        return num;
    }
};