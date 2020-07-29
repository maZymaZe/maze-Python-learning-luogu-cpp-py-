class Solution {
public:
    int hammingDistance(int x, int y) {
        int t=x^y,ans=0;
        while(t)t-=(-t&t),ans++;
        return ans;

    }
};