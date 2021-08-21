class Solution {
   public:
    bool isStrobogrammatic(string num) {
        int l = num.size();
        for (int i = 0; i < l; i++) {
            if ((num[i] == '9' && num[l - i - 1] == '6') ||
                (num[i] == '8' && num[l - i - 1] == '8') ||
                (num[i] == '6' && num[l - i - 1] == '9') ||
                (num[i] == '1' && num[l - i - 1] == '1') ||
                (num[i] == '0' && num[l - i - 1] == '0'))
                ;
            else
                return false;
        }
        return true;
    }
};