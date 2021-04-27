class Solution {
public:
    int reverseBits(int num) {
        if(num==0)return 1;
        int d[40]={0},cd=0,cl[40]={0},cr[40]={0},c1=0,c0=0;
        for(int i=1;i<=32;i++){
            d[++cd]=num&1;
            num>>=1;
        }
        for(int i=1;i<=cd;i++){
            if(d[i-1]==0)cl[i]=0;
            else cl[i]=cl[i-1]+1;
        }
        for(int i=cd;i>0;i--){
            if(d[i+1]==0)cr[i]=0;
            else cr[i]=cr[i+1]+1;
            if(d[i]==0)c0++;
            else c1++;
        }
        if(c0==cd)return 1;
        if(c1==cd)return c1;
        int ans=0;
        for(int i=1;i<=cd;i++){
            if(d[i]==0)ans=max(ans,1+cl[i]+cr[i]);
        }
        return ans;
    }
};