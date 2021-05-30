class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool flag=false;
        while (n){
            if(flag)return false;
            if(n&1)flag=true;
            n>>=1;
        }
        return flag;
    }
};