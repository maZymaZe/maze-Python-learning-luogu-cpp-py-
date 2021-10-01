class Solution {
   public:
    bool ck(vector<int>& postorder, int x, int y) {
        int l = y - x + 1;
        if (l <= 1)
            return 1;
        int p = y - 1;
        while (p >= x && postorder[p] > postorder[y])
            p--;
        for (int i = x; i <= p; i++) {
            if (postorder[i] > postorder[y])
                return false;
        }
        return ck(postorder, x, p) && ck(postorder, p + 1, y - 1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return ck(postorder, 0, postorder.size() - 1);
    }
};