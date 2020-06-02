class Solution {
public:
    int sumNums(int n) {
        int res=n;
        n&&(res+=sumNums(n-1));
        return res;
    }
};