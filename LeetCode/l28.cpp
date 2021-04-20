class Solution {
public:
    int strStr(string haystack, string needle) {
        int lh=haystack.size(),ln=needle.size();
        if(ln==0) return 0;
        if(lh<ln)return -1;
        vector<int> nex(ln+1);
        nex[0]=-1;
        for(int i=1;i<ln;i++){
            int j=nex[i-1];
            while(needle[j+1]!=needle[i]&&j>=0){
                j=nex[j];
            }
            if(needle[j+1]==needle[i]){
                nex[i]=j+1;
            }else nex[i]=-1;
        }
        int ph=0,pn=0;
        while(ph<lh){
            if(haystack[ph]==needle[pn]){
                pn++,ph++;
            }else {
                if(pn==0)ph++;
                else pn=nex[pn-1]+1;
            }
            if(pn==ln){
                return ph-ln;
            }
        }
        return -1;     
    }
};