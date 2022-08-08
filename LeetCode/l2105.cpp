class Solution {
   public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int res = 0;                 // 灌满水罐次数
        int n = plants.size();       // 两人位置
        int posa = 0, posb = n - 1;  // 两人剩余水量
        int vala = capacityA, valb = capacityB;
        // 模拟相遇前的浇水过程
        while (posa < posb) {
            if (vala < plants[posa]) {
                ++res;
                vala = capacityA - plants[posa];
            } else {
                vala -= plants[posa];
            }
            ++posa;
            if (valb < plants[posb]) {
                ++res;
                valb = capacityB - plants[posb];
            } else {
                valb -= plants[posb];
            }
            --posb;
        }
        // 模拟相遇后可能的浇水过程
        if (posa == posb) {
            if (vala >= valb && vala < plants[posa]) {
                ++res;
            }
            if (vala < valb && valb < plants[posb]) {
                ++res;
            }
        }
        return res;
    }
};
