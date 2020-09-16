struct pr{
    string a,b;
    bool operator <(const pr& x){
        return a<x.a||(a==x.a&&b<x.b);
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int l=strs.size();
        if(!l)return ans;
        vector<pr> v(l);
        for(int i=0; i<l; i++){
            v[i]={strs[i],strs[i]};
            sort(v[i].a.begin(),v[i].a.end());
        }
        sort(v.begin(),v.end());
        vector<string> tmp;
        tmp.push_back(v[0].b);
        string pre=v[0].a;
        for(int i=1;i<l;i++){
            if(v[i].a==pre){
                tmp.push_back(v[i].b);
            }
            else{
                ans.push_back(tmp);
                tmp.clear();
                tmp.push_back(v[i].b);
                pre=v[i].a;
            }
        }
        if(tmp.size())ans.push_back(tmp);
        return ans;
    }
};