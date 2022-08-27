class Solution {
   public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long ans = 0x7FFFFFFF;
        int l1 = a.size(), l2 = b.size(), p1 = 0, p2 = 0;
        while (p1 < l1 && p2 < l2) {
            ans = min(ans, abs((long long)a[p1] - b[p2]));
            if (a[p1] < b[p2])
                p1++;
            else
                p2++;
        }
        return ans;
    }
};