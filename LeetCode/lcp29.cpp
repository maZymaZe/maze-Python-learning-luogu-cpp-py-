class Solution {
   public:
    int orchestraLayout(int num, int xPos, int yPos) {
        int dep = min(min(xPos + 1, num - xPos), min(yPos + 1, num - yPos));
        int len = num - (dep - 1) * 2;
        long long pre = 1ll * num * num - 1ll * len * len;
        if (xPos == dep - 1) {
            pre += (yPos - (dep - 1) + 1);
            return (pre - 1) % 9 + 1;
        }
        pre += len - 1;
        if (yPos == dep - 1 + len - 1) {
            pre += xPos - (dep - 1) + 1;
            return (pre - 1) % 9 + 1;
        }
        pre += len - 1;
        if (xPos == dep - 1 + len - 1) {
            pre += (dep - 1 + len - 1 - yPos + 1);
            return (pre - 1) % 9 + 1;
        }
        pre += len - 1;
        pre += (dep - 1 + len - 1 - xPos + 1);
        return (pre - 1) % 9 + 1;
    }
};