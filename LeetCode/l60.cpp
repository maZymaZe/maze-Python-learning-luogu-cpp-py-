class Solution {
public:
    string getPermutation(int n, int k) {
        if(n==1)return string("1");
        int jx[10] = {1}, ans[10] = {0}, p[10] = {1};
        for (int i = 1; i < 10; i++)
            jx[i] = jx[i - 1] * i, p[i] = i + 1;
        for (int i = n - 1; i >= 2; i--) {
            int t = (k-1) / jx[i];
            ans[i] = p[t];
            for (int j = t; j < 9; j++)
                p[j] = p[j + 1];
            k = (k-1)%jx[i]+1;
        }
        if(k==1)ans[1]=p[0],ans[0]=p[1];
        else ans[1]=p[1],ans[0]=p[0];
        string ret;
        for (int i = n - 1; i >= 0; i--)
            ret += to_string(ans[i]);
        return ret;
    }
};