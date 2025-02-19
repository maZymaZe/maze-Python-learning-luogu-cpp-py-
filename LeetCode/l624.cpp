class Solution {
   public:
    int maxDistance(vector<vector<int>>& arrays) {
        int l = arrays.size();
        int x[2], px[2], y[2], py[2];
        auto swx = [&]() {
            swap(x[0], x[1]);
            swap(px[0], px[1]);
        };
        auto swy = [&]() {
            swap(y[0], y[1]);
            swap(py[0], py[1]);
        };
        x[0] = arrays[0].front();
        px[0] = 0;
        x[1] = arrays[1].front();
        px[1] = 1;

        if (x[0] > x[1])
            swx();

        y[0] = arrays[0].back();
        py[0] = 0;
        y[1] = arrays[1].back();
        py[1] = 1;

        if (y[0] < y[1])
            swy();

        for (int i = 2; i < l; i++) {
            if (arrays[i].front() < x[1]) {
                x[1] = arrays[i].front();
                px[1] = i;
            }
            if (x[0] > x[1])
                swx();
            if (arrays[i].back() > y[1]) {
                y[1] = arrays[i].back();
                py[1] = i;
            }
            if (y[0] < y[1])
                swy();
        }
        int ans = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (px[i] != py[j])
                    ans = max(ans, y[j] - x[i]);
            }
        }
        return ans;
    }
};