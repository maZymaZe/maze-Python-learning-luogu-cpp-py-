class Solution {
   public:
    string intToRoman(int num) {
        int a[5];
        for (int i = 1; i <= 4; i++) {
            a[i] = num % 10;
            num /= 10;
        }
        string result;
        if (a[4]) {
            for (int i = 0; i < a[4]; i++) {
                result += 'M';
            }
        }
        if (a[3] == 4) {
            result += "CD";
        } else if (a[3] == 9) {
            result += "CM";
        } else {
            if (a[3] >= 5) {
                result += "D";
                a[3] -= 5;
            }

            for (int i = 0; i < a[3]; i++) {
                result += 'C';
            }
        }
        if (a[2] == 4) {
            result += "XL";
        } else if (a[2] == 9) {
            result += "XC";
        } else {
            if (a[2] >= 5) {
                result += "L";
                a[2] -= 5;
            }

            for (int i = 0; i < a[2]; i++) {
                result += 'X';
            }
        }
        if (a[1] == 4) {
            result += "IV";
        } else if (a[1] == 9) {
            result += "IX";
        } else {
            if (a[1] >= 5) {
                result += "V";
                a[1] -= 5;
            }

            for (int i = 0; i < a[1]; i++) {
                result += 'I';
            }
        }
        return result;
    }
};