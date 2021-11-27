class Solution {
   public:
    double minRecSize(vector<vector<int>>& lines) {
        int n = lines.size();
        vector<int> k(n), b(n);
        sort(lines.begin(), lines.end());
        for (int i = 0; i < n; i++) {
            k[i] = lines[i][0], b[i] = lines[i][1];
        }
        int p = 0, q = 0;
        while (q < n && k[p] == k[q])
            q++;
        if (q >= n)
            return 0;
        double xmi = 1e100, xma = -1e100, ymi = 1e100, yma = -1e100;
        while (q < n) {
            int r = q;
            while (r + 1 < n && k[r + 1] == k[q])
                r++;
            double cx1 = 1.0 * (b[r] - b[p]) / (k[r] - k[p]);
            double cx2 = 1.0 * (b[q] - b[q - 1]) / (k[q] - k[q - 1]);
            xmi = min(xmi, min(cx1, cx2));
            xma = max(xma, max(cx1, cx2));
            double cy1 = 1.0 * (b[r] * k[p] - b[p] * k[r]) / (k[r] - k[p]);
            double cy2 =
                1.0 * (b[q] * k[q - 1] - b[q - 1] * k[q]) / (k[q] - k[q - 1]);
            ymi = min(ymi, min(cy1, cy2));
            yma = max(yma, max(cy1, cy2));
            p = q;
            while (q < n && k[q] == k[p])
                q++;
        }
        return (xma - xmi) * (yma - ymi);
    }
};