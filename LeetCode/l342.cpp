class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        while(n){
            if(n==1)return true;
            if(n&3)return false;
            n>>=2;
        }
        return false;
    }
};