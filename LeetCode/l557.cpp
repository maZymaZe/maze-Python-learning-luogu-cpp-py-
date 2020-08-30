class Solution {
public:
    string reverseWords(string s) {
        s+=' ';int len = s.size(),l=0,r=0;
        while(r<len) {
            while(r<len&&s[r]!=' ')r++;
            string ll=s.substr(0,l),mm=s.substr(l,r-l),rr=s.substr(r,len);
            reverse(mm.begin(), mm.end());
            s=ll+mm;
            if(rr.size()>1)s+=rr;
            ++r;
            l=r;
        }
        return s;
    }
};