class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size();
        digits[l - 1]++;
        for (int i = l - 1; i > 0; i--) {
            digits[i - 1] += digits[i] / 10;
            digits[i] %= 10;
        }
        if (digits[0] == 10) {
            digits[0] = 0;
            digits.push_back(digits.back());

            for (int i = l - 1; i > 0; i--) {
                digits[i] = digits[i - 1];
            }
            digits[0] = 1;
        }
        return digits;
    }
};