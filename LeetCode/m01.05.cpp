class Solution {
   public:
    bool oneEditAway(string first, string second) {
        int l1 = first.size(), l2 = second.size();
        if (l1 == l2) {
            int f = 0;
            for (int i = 0; i < l1; i++) {
                if (first[i] != second[i]) {
                    f++;
                }
            }
            return f < 2;
        }
        if (l1 > l2) {
            swap(l1, l2);
            swap(first, second);
        }
        int f = 0, p = 0, q = 0;
        for (int i = 0; i < l1; i++) {
            if (first[p] == second[q])
                p++, q++;
            else {
                if (f)
                    return false;
                f = 1;
                q++;
                i--;
            }
        }
        return l1 == l2 - 1;
    }
};