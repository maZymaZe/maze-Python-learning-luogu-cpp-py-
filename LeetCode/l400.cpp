class Solution {
public:
    int findNthDigit(int n) {
        int lm=9,p=1;
        while((long long)n>=(long long)lm*p){
            n-=lm*p;
            lm=lm*10;
            p++;
        }

        if(n==0)return 9;
        int base=1;
        int w=p-1;
        while(w--)base*=10;
        base--;

        int cnt=n/p;
        base+=cnt;
        if(n%p==0)return base%10;
        base++;
        int r=n%p;
        int t=p-r;
        while(t--)base/=10;
        return base%10; 
    }
};