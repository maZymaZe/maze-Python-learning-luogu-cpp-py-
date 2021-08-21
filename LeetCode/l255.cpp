class Solution {
   public:
    bool ck(vector<int>& preorder, int l, int r) {
        if (l >= r)
            return true;
        int lim = preorder[l];
        for (int i = l + 1; i <= r; i++) {
            if (preorder[i] > lim) {
                for (int j = i; j <= r; j++) {
                    if (preorder[j] <= lim)
                        return false;
                }
                return ck(preorder, l + 1, i - 1) && ck(preorder, i, r);
            }
        }
        return ck(preorder, l + 1, r);
    }
    bool verifyPreorder(vector<int>& preorder) {
        int len = preorder.size();
        return ck(preorder, 0, len - 1);
    }
};