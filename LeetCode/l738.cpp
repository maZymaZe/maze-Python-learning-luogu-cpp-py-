class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int cnt=0,n=N,a[30]={0},p,ret=0;
        while(n){
            a[++cnt]=n%10;
            n /= 10;
        }
        for(int i=cnt;i>1;i--){
            if(a[i]>a[i-1]){
                p=i-1;
                for(int j=p;j>0;j--)a[j]=9;
                p++;
                while(p+1<=cnt&&a[p]==a[p+1]){
                    a[p]=9;
                    p++;
                }
                a[p]--;
                for(int j=cnt;j>0;j--){
                    ret=ret*10+a[j];
                }
                return ret;
            }
        }
        return N;
    }
};