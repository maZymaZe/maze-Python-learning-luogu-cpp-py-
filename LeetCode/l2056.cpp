class Movement {
   public:
    Movement(int start_x, int start_y, int end_x, int end_y, int dx, int dy)
        : start_x_(start_x),
          start_y_(start_y),
          end_x_(end_x),
          end_y_(end_y),
          dx_(dx),
          dy_(dy),
          cur_x_(start_x),
          cur_y_(start_y) {}

    void reset() {
        cur_x_ = start_x_;
        cur_y_ = start_y_;
    }

    bool stopped() { return cur_x_ == end_x_ && cur_y_ == end_y_; }

    void advance() {
        if (!stopped()) {
            cur_x_ += dx_;
            cur_y_ += dy_;
        }
    }

    bool cross(Movement& oth) {
        // 每次判断是否相遇时需要重置 cur
        reset();
        oth.reset();
        while (!stopped() || !oth.stopped()) {
            advance();
            oth.advance();
            if (cur_x_ == oth.cur_x_ && cur_y_ == oth.cur_y_) {
                return true;
            }
        }
        return false;
    }

   public:
    const int start_x_;
    const int start_y_;
    const int end_x_;
    const int end_y_;
    const int dx_;
    const int dy_;
    int cur_x_;
    int cur_y_;
};

class Solution {
   public:
    int countCombinations(vector<string>& pieces,
                          vector<vector<int>>& positions) {
        vector<vector<int>> rook_dire_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> bishop_dire_ = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        vector<vector<int>> queen_dire_ = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                                           {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int n = pieces.size();
        int res = 0;
        vector<Movement> stk;

        // 判断第 u 个棋子是否之前的棋子在移动过程中相遇
        auto check = [&](int u) {
            for (int v = 0; v < u; v++) {
                if (stk[u].cross(stk[v])) {
                    return false;
                }
            }
            return true;
        };

        function<void(int)> dfs = [&](int u) {
            if (u == n) {
                res++;
                return;
            }
            vector<vector<int>> dire;
            if (pieces[u] == "rook") {
                dire = rook_dire_;
            } else if (pieces[u] == "queen") {
                dire = queen_dire_;
            } else if (pieces[u] == "bishop") {
                dire = bishop_dire_;
            }

            // 处理第 u 个棋子原地不动的情况
            stk.push_back(Movement(positions[u][0], positions[u][1],
                                   positions[u][0], positions[u][1], 0, 0));
            if (check(u)) {
                dfs(u + 1);
            }
            stk.pop_back();

            // 枚举第 u 个棋子在所有方向、所有步数的情况
            for (int i = 0; i < dire.size(); i++) {
                for (int j = 1; j < 8; j++) {
                    int x = positions[u][0] + dire[i][0] * j;
                    int y = positions[u][1] + dire[i][1] * j;
                    if (x < 1 || x > 8 || y < 1 || y > 8) {
                        break;
                    }
                    stk.push_back(Movement(positions[u][0], positions[u][1], x,
                                           y, dire[i][0], dire[i][1]));
                    if (check(u)) {
                        dfs(u + 1);
                    }
                    stk.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }
};
