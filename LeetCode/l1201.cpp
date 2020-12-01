class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab=(long long)a*(b/__gcd(a,b)),bc=(long long)b*(c/__gcd(b,c)),ac=(long long)a*(c/__gcd(a,c));
        long long abc=(long long)a*(bc/__gcd((long long)a,bc));
        long long l=1,r=1e10;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long cnt=mid/a+mid/b+mid/c-mid/ab-mid/bc-mid/ac+mid/abc;
            if(cnt>=n)r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};