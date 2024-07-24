class Solution {
   public:
    int minimumOperations(string num) {
        int l = num.size();
        int h0 = 0, h5 = 0, c0 = 0;
        for (int i = l - 1; i >= 0; i--) {
            if (num[i] == '0')
                c0++;
            if (h0 && (num[i] == '0' || num[i] == '5')) {
                return l - i - 2;
            }
            if (h5 && (num[i] == '2' || num[i] == '7')) {
                return l - i - 2;
            }
            if (!h0 && num[i] == '0')
                h0 = 1;
            if (!h5 && num[i] == '5')
                h5 = 1;
        }
        return l - c0;
    }
};