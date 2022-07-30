
class Solution {
   private:
    // 记录列数和列数（因为方阵是相等的）
    int n;

    // 计算时候最大的范围，避免引入不再考虑范围的计算值
    int mask;

    // 计算bit为1的数量
    int CntOneBit(int num) {
        int cnt = 0;
        while (num > 0) {
            if ((num & 1) == 1) {
                ++cnt;
            }
            num >>= 1;
        }

        return cnt;
    }

    // 计算最小步数的函数
    // codex,numx对应的就是排列类型和对应的数量
    int CalculateSteps(unordered_map<int, int>& code2num) {
        int codes[2];
        int nums[2];
        int cnt = 0;
        // 从map获得num和code,这里正好2个（之前已经判断了）
        for (auto iter = code2num.begin(); iter != code2num.end(); ++iter) {
            codes[cnt] = iter->first;
            nums[cnt] = iter->second;
            ++cnt;
        }
        // cout << "CalculateSteps " << codes[0] << "," << codes[1] << " " <<
        // nums[0] << "," << nums[1] << endl;

        // 判断数量是否符合预期: 默认第一个计数更大
        if (nums[0] < nums[1]) {
            swap(nums[0], nums[1]);
            swap(codes[0], codes[1]);
        }
        if (nums[0] != (n + 1) / 2 || nums[1] != n / 2) {
            // cout << "wrong n" << endl;
            return -1;
        }

        // 正好需要异或互补：长度为n的数量
        if ((codes[0] ^ codes[1]) != mask) {
            // cout << "wrong xor " << (codes[0] ^ codes[1]) << endl;
            return -1;
        }
        // 开始计算最小步数，考虑两种情况 0x55555555 或 0xaaaaaaaa
        // 最小步数即计算异或后的1的位数/2（记得即考虑mask范围内的1）
        //
        if (n % 2 == 0) {
            return min(CntOneBit((codes[0] ^ 0x55555555) & mask),
                       CntOneBit((codes[0] ^ 0xaaaaaaaa) & mask)) >>
                   1;
        } else {
            int code = CntOneBit(codes[0]) > (n / 2) ? codes[0] : codes[1];
            return CntOneBit((code ^ 0x55555555) & mask) / 2;
        }
    }

   public:
    int movesToChessboard(vector<vector<int>>& board) {
        n = board.size();
        mask = (1 << n) - 1;

        // 两种排列类型
        unordered_map<int, int> code2num;

        // 先计算行的情况
        for (int i = 0; i < n; ++i) {
            // 当前的排列类型
            int curr = 0;
            for (int j = 0; j < n; ++j) {
                curr = (curr << 1) + board[i][j];
            }
            // 排除出现第三种排列情况，直接返回失败 -1
            ++code2num[curr];
            if (code2num.size() > 2) {
                return -1;
            }
        }
        int stepsRow = CalculateSteps(code2num);
        if (stepsRow == -1) {
            return -1;
        }

        code2num.clear();
        // 按照列的情况
        for (int j = 0; j < n; ++j) {
            // 当前的排列类型
            int curr = 0;
            for (int i = 0; i < n; ++i) {
                curr = (curr << 1) + board[i][j];
            }
            // 排除出现第三种排列情况，直接返回失败 -1
            ++code2num[curr];
            if (code2num.size() > 2) {
                return -1;
            }
        }

        int stepsCol = CalculateSteps(code2num);
        if (stepsCol == -1) {
            return -1;
        }

        return stepsRow + stepsCol;
    }
};
