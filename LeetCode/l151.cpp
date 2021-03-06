class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int r=s.size()-1,l,f=0;
        while(1){
            while(r>=0&&s[r]==' ')r--;
            l=r;
            while(l>=0&&s[l]!=' ')l--;
            l++;
            if(f)ans+=" ";
            else f=1;
            ans+=s.substr(l,r-l+1);
            r=l-1;
            if(r<0)break;
        }
        return ans;
    }
};