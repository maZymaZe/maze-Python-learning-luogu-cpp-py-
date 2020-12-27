class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int l=s.size();
        int ms[260]={0},ps=0,mt[260]={0},pt=0;
        vector<int> cs(l),ct(l);
        for(int i=0;i<l;i++){
            if(!ms[s[i]])
                ms[s[i]]=++ps;               
            cs[i]=ms[s[i]];
        }
        for(int i=0;i<l;i++){
            if(!mt[t[i]])
                mt[t[i]]=++pt;               
            ct[i]=mt[t[i]];
        }
        for(int i=0;i<l;i++)if(cs[i]!=ct[i])return false;
        return true;
    }
};