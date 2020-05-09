class Solution {
public:
    int arrangeCoins(int n) {
        long long x=0;
        while(n>=(x+1)*x/2)x++;
        return x-1;
    }
};