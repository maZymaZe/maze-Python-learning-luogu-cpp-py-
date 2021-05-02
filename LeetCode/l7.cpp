class Solution {
public:
    int reverse(int x) {
        if(x==0x80000000)return 0;
        int f=x>=0?1:-1,d[14]={0},c=0;
        x=abs(x);
        while(x){
            d[++c]=x%10;
            x/=10;
        }
        int ret=0;
        for(int i=1;i<=c;i++){
            if(1.0*(0x7FFFFFFF-d[i])/10<ret)return 0;
            ret=ret*10+d[i];
            if(ret<0)return 0;
        }
        return ret*f;
    }
};