class Solution {
   public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int tot = 0;
        string t = to_string(x);
        for (char c : t)
            tot += c - '0';
        return (x % tot) ? -1 : tot;
    }
};