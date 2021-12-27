class Solution {
   public:
    bool isFlipedString(string s1, string s2) {
        string s3 = s1 + s1;
        if (s1.length() != s2.length())
            return false;
        int l3 = s3.length(), l2 = s2.length();
        if (l2 == 0)
            return true;
        vector<int> nx(l2);
        nx[0] = -1;
        for (int i = 1; i < l2; i++) {
            int j = nx[i - 1];
            while (s2[j + 1] != s2[i] && j >= 0)
                j = nx[j];
            if (s2[j + 1] == s2[i])
                nx[i] = j + 1;
            else
                nx[i] = -1;
        }
        int p3 = 0, p2 = 0;
        while (p3 < l3) {
            if (s2[p2] == s3[p3]) {
                p2++, p3++;
            } else if (p2 == 0)
                p3++;
            else
                p2 = nx[p2 - 1] + 1;
            if (p2 == l2)
                return true;
        }
        return false;
    }
};