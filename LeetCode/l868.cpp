class Solution {
public:
    int binaryGap(int n) {
        while(n%2==0)n/=2;
        int cnt=-1,r=0,p=0;
        while(n){
            int t=n%2;
            if(t){
                cnt++;
                if(cnt>r)r=cnt;
                cnt=0;
            }else cnt++;
            n/=2;
        }
        return  r;
    }
};