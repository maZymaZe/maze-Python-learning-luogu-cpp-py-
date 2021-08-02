class Solution {
   public:
    bool ck(vector<int>& p1,
            vector<int>& p2,
            vector<int>& p3,
            vector<int>& p4) {
        if (p1[0] == p2[0] && p1[1] == p2[1])
            return false;
        if (p3[0] == p4[0] && p3[1] == p4[1])
            return false;
        if (p1[0] + p2[0] != p3[0] + p4[0] || p1[1] + p2[1] != p3[1] + p4[1])
            return false;
        if ((p1[0] - p2[0]) * (p3[0] - p4[0]) +
                (p1[1] - p2[1]) * (p3[1] - p4[1]) !=
            0)
            return false;
        if ((p1[0] - p2[0]) * (p1[0] - p2[0]) +
                (p1[1] - p2[1]) * (p1[1] - p2[1]) !=
            (p3[0] - p4[0]) * (p3[0] - p4[0]) +
                (p3[1] - p4[1]) * (p3[1] - p4[1]))
            return false;
        return true;
    }
    bool validSquare(vector<int>& p1,
                     vector<int>& p2,
                     vector<int>& p3,
                     vector<int>& p4) {
        return ck(p1, p2, p3, p4) || ck(p1, p3, p2, p4) || ck(p1, p4, p2, p3);
    }
};