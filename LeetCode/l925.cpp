class Solution {
   public:
    bool isLongPressedName(string name, string typed) {
        int l1 = name.size(), l2 = typed.size(), p1 = 0, p2 = 0;
        while (p1 < l1 && p2 < l2) {
            if (name[p1] == typed[p2])
                p1++, p2++;
            else {
                if (p2 > 0 && typed[p2 - 1] == typed[p2])
                    p2++;
                else
                    return false;
            }
        }
        if (p1 == l1 && p2 == l2)
            return true;
        if (p1 != l1)
            return false;
        while (p2 > 0 && p2 < l2 && typed[p2] == typed[p2 - 1])
            p2++;
        if (p2 == l2)
            return true;
        return false;
    }
};