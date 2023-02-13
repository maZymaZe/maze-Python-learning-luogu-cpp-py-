class Solution {
   public:
    vector<int> minOperations(string boxes) {
        int l = boxes.size(), totr = 0, totl = (boxes[0] == '1');
        vector<int> ans(l);
        for (int i = 1; i < l; i++) {
            if (boxes[i] == '1')
                ans[0] += i, totr++;
        }
        for (int i = 1; i < l; i++) {
            ans[i] = ans[i - 1];
            ans[i] -= totr;
            ans[i] += totl;
            totr -= (boxes[i] == '1');
            totl += (boxes[i] == '1');
        }
        return ans;
    }
};