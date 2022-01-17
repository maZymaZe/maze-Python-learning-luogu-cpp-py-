class Solution {
   public:
    vector<int> findClosedNumbers(int num) {
        int count = 0;  // 记录1的数量
        int big = -1, small = -1;
        int numTmp = num;
        for (int i = 0; i < 30; i++) {
            // 遇到01，把他变为10，并且把右侧的1放到最右边
            if ((num & (1 << i)) != 0 && (num & (1 << i + 1)) == 0) {
                numTmp += (1 << i + 1);
                numTmp -= (1 << i);
                for (int j = 0; j < count; j++) {
                    numTmp += (1 << j);
                }
                big = numTmp;
                break;
            }
            if ((num & (1 << i)) != 0)
                count++;
            numTmp &= (~(1 << i));
        }
        numTmp = num;
        count = 0;
        for (int i = 0; i < 30; i++) {
            // 遇到10，把他变为01，并且把右侧的1放到最左边
            if ((num & (1 << i)) == 0 && (num & (1 << i + 1)) != 0) {
                numTmp -= (1 << i + 1);
                numTmp += (1 << i);
                for (int j = 0; j < count; j++) {
                    numTmp += (1 << i - j - 1);
                }
                small = numTmp;
                break;
            }
            if ((num & (1 << i)) != 0)
                count++;
            numTmp &= (~(1 << i));
        }
        return {big, small};
    }
};