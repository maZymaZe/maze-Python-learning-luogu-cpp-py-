class Solution {
   public:
    void f(vector<int>& A, vector<int>& B, vector<int>& C, int l) {
        if (l == 0)
            return;
        f(A, C, B, l - 1);
        C.push_back(A.back());
        A.pop_back();
        f(B, A, C, l - 1);
    }
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        f(A, B, C, A.size());
    }
};