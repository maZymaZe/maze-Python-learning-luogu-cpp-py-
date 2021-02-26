class Solution {
public:
    int balancedStringSplit(string s) {
        int l=0,r=0,len=s.length(),ans=0;
        for(int i=0;i<len;i++){
            if(s[i]=='L')l++;
            else r++;
            if(l==r&&l!=0)ans++,l=r=0;
        }
        return ans;
    }
};