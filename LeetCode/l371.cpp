class Solution {
public:
    int getSum(int a, int b) {
        int c=a&b;
        if(!c)return a|b;
        return getSum((unsigned int)c<<1,(a|b)^c);
    }
};