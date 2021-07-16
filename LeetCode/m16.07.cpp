class Solution {
public:
    int maximum(int a, int b) {
        int t=(((long long)a-b)>>63)&1;
        return b*t+a*(!t);
    }
};