class Solution {
   public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });
        int l = boxTypes.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            int c = min(boxTypes[i][0], truckSize);
            truckSize -= c;
            ans += c * boxTypes[i][1];
        }
        return ans;
    }
};