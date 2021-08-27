class Solution {
   public:
    string one(int x) {
        switch (x) {
            case 1:
                return "One";
            case 2:
                return "Two";
            case 3:
                return "Three";
            case 4:
                return "Four";
            case 5:
                return "Five";
            case 6:
                return "Six";
            case 7:
                return "Seven";
            case 8:
                return "Eight";
            case 9:
                return "Nine";
        }
        return "";
    }
    string twolessthan20(int x) {
        switch (x) {
            case 10:
                return "Ten";
            case 11:
                return "Eleven";
            case 12:
                return "Twelve";
            case 13:
                return "Thirteen";
            case 14:
                return "Fourteen";
            case 15:
                return "Fifteen";
            case 16:
                return "Sixteen";
            case 17:
                return "Seventeen";
            case 18:
                return "Eighteen";
            case 19:
                return "Nineteen";
        }
        return "";
    }
    string ten(int x) {
        switch (x) {
            case 2:
                return "Twenty";
            case 3:
                return "Thirty";
            case 4:
                return "Forty";
            case 5:
                return "Fifty";
            case 6:
                return "Sixty";
            case 7:
                return "Seventy";
            case 8:
                return "Eighty";
            case 9:
                return "Ninety";
        }
        return "";
    }
    string two(int x) {
        if (!x)
            return "";
        if (x < 10)
            return one(x);
        if (x < 20)
            return twolessthan20(x);
        int tenn = x / 10;
        int r = x - tenn * 10;
        if (r)
            return ten(tenn) + " " + one(r);
        return ten(tenn);
    }
    string three(int x) {
        int hundred = x / 100;
        int r = x - hundred * 100;
        string res = "";
        if (hundred * r != 0) {
            res = one(hundred) + " Hundred " + two(r);
        } else if (hundred == 0 && r != 0) {
            res = two(r);
        } else if (hundred != 0 && r == 0) {
            res = one(hundred) + " Hundred";
        }
        return res;
    }
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        int bil = num / 1000000000;
        num -= bil * 1000000000;
        int mil = num / 1000000;
        num -= mil * 1000000;
        int tho = num / 1000;
        num -= tho * 1000;
        string ret = "";
        if (bil)
            ret += three(bil) + " Billion";
        if (mil) {
            if (ret.size())
                ret += " ";
            ret += three(mil) + " Million";
        }
        if (tho) {
            if (ret.size())
                ret += " ";
            ret += three(tho) + " Thousand";
        }
        if (num) {
            if (ret.size())
                ret += " ";
            ret += three(num);
        }
        return ret;
    }
};