class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l=0,r,len=s.size(),ans=0,cn=maxCost;
        while(l<len&&cn<abs(s[l]-t[l]))l++;
        if(l==len)return 0;
        r=l;
        while(r<len){
            while(r<len&&cn>=abs(s[r]-t[r])){
                cn-=abs(s[r]-t[r]);
                r++;
            }
            if(r-l>ans)ans=r-l;
            if(abs(s[r]-t[r])>maxCost){
                r++;
                l=r;
                cn=maxCost;
                continue;
            }
            cn+=abs(s[l]-t[l]);
            l++;
        }
        return ans;
    }
};