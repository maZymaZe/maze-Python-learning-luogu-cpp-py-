class Solution {
public:
    double ans;
    void work(double x,long long n){
        ans=1;
        while(n){
            if(n&1)ans*=x;
            x*=x;
            n>>=1;
        }
    }
    double myPow(double x, int n) {
        if(n==0)return 1;
        long long t=n;
        if(t<0)t=-t,x=1.0/x;
        work(x,t);
        return ans;
    }
};