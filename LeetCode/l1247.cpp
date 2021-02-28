class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xc=0,yc=0,l=s1.length(),ans=0;
        for(int i=0;i<l;i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x')xc++;
                else yc++;
            }
        }
        ans+=xc/2+yc/2;
        xc%=2,yc%=2;
        if(xc&&yc)xc=yc=0,ans+=2;
        if(xc||yc)return -1;
        return ans;
    }
};