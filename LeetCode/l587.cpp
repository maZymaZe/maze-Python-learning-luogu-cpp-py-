struct POINT {
    int x, y;
    POINT(int xx = 0, int yy = 0) {
        x = xx;
        y = yy;
    }
    bool operator<(const POINT& other) const {
        return x == other.x ? y < other.y : x < other.x;
    }
    POINT operator-(const POINT& other) {
        POINT ret;
        ret.x = x - other.x;
        ret.y = y - other.y;
        return ret;
    }
    int operator^(const POINT& other) { return x * other.y - y * other.x; }
};
class Solution {
   public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        vector<POINT> arr;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            arr.push_back({points[i][0], points[i][1]});
        }
        sort(arr.begin(), arr.end());
        int tp = 0;
        vector<int> usd(n);
        vector<int> st(n + 10);
        for (int i = 0; i < n; i++) {
            while (tp >= 2 && (((arr[st[tp]] - arr[st[tp - 1]]) ^
                                (arr[i] - arr[st[tp]])) < 0)) {
                usd[st[tp--]] = 0;
            }
            st[++tp] = i;
            usd[i] = 1;
        }
        usd[0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (usd[i])
                continue;
            while (tp >= 2 && (((arr[st[tp]] - arr[st[tp - 1]]) ^
                                (arr[i] - arr[st[tp]])) < 0)) {
                usd[st[tp--]] = 0;
            }
            st[++tp] = i;
            usd[i] = 1;
        }
        vector<vector<int>> ret;
        for (int i = 1; i < tp; i++) {
            ret.push_back({arr[st[i]].x, arr[st[i]].y});
        }
        return ret;
    }
};