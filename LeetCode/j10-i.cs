public class Solution {
    public int Fib(int n) {
        if(n==0)return 0;
        int a=0,b=1,t;
        for(int i=1;i<n;i++){
            t=(a+b)%1000000007;
            a=b;
            b=t;
        }
        return b;       
    }
}