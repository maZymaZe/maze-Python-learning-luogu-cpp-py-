struct pr{
    string a, b;
    bool operator <(const pr& x) {
        return b<x.b;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int l=strs.size();
        vector<vector<string>> ret;
        if(l==0)return ret;
        vector<pr> c(l);
        for(int i=0; i<l;i++){
            c[i].a=strs[i];
            c[i].b=strs[i];
            sort(c[i].b.begin(),c[i].b.end());
        }
        sort(c.begin(),c.end());
        ret.push_back(vector<string>());
        ret[0].push_back(c[0].a);
        string pre=c[0].b;
        int n=0;
        for(int i=1;i<l;i++){
            if(c[i].b==pre){
                ret[n].push_back(c[i].a);
            }else{
                ret.push_back(vector<string>());
                ret[++n].push_back(c[i].a);
                pre=c[i].b;
            }
        }
        return ret;

    }
};