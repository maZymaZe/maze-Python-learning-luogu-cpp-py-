class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long w=x,t=0;
        while(w){
            t=t*10+w%10;
            w/=10;
        }
        return t==x;
    }
};