class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n=s.size();
        if(n==0||words.empty()) return res;
        int ws=words[0].size(),nw=words.size();
        unordered_map<string, int> mp;
        for(string&w:words){
            ++mp[w];
        }
        for(int i=0;i<ws;i++){
            int l=i,r=i,c=0;
            unordered_map<string, int> cmp;
            while(r+ws<=n){
                string crw=s.substr(r,ws);
                r+=ws;
                if(mp.count(crw)){
                    ++cmp[crw];
                    ++c;
                    while(cmp[crw]>mp[crw]){
                        string ts=s.substr(l,ws);
                        l+=ws;
                        --c;
                        --cmp[ts];
                    }
                    if(c==nw)res.push_back(l);
                }else {
                    l=r;
                    c=0;
                    cmp.clear();
                }
            }
           
        }
        return res;

    }
};