
class Solution {
   private:
    // 构建输入字符串（长度为2）和输出的字符
    unordered_map<string, vector<char>> str2char;

    // 递归函数 r是行数范围0~n-1,c是列数范围是0~c
    bool dfs(vector<string>& tower, int r, int c) {
        // 这一行已经遍历完了
        if (r == c) {
            c = 0;
            --r;
        }
        // 遍历结束
        if (r == 0) {
            return true;
        }

        string curr = tower[r].substr(c, 2);
        if (str2char.find(curr) == str2char.end()) {
            return false;
        }

        // 考虑各种可映射c的可能性
        for (char ch : str2char[curr]) {
            tower[r - 1].push_back(ch);
            // 找到了就直接返回，无需再回溯
            if (dfs(tower, r, c + 1)) {
                return true;
            }
            // 回溯非常重要
            tower[r - 1].pop_back();
        }
        return false;
    }

   public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();
        // 预先构建好每一层的内容
        vector<string> tower(n);
        // 最后一层就是输入bottom
        tower[n - 1] = bottom;
        for (const string& s : allowed) {
            str2char[s.substr(0, 2)].emplace_back(s[2]);
        }

        return dfs(tower, n - 1, 0);
    }
};
