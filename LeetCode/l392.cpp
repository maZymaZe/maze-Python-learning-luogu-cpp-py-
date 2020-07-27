class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ps=0,pt=0,lt=t.size(),ls=s.size();
        if(ls==lt&&ls==0)return true;
        while(pt<lt){
            if(t[pt]==s[ps])ps++;
            if(ps==ls)return true;
            pt++;
        }
        return false;
    }
};