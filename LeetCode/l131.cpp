class Solution {
public:
    int l;
    vector<vector<vector<string>>> mp;
    bool ck(string&s,int l,int r){
        while(l<r){
            if(s[l]!=s[r])return false;
            l++,r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        l=s.size();
        mp.resize(l);
        for(int i=l-1; i>=0; i--){
            for(int j=i;j<l;j++){
                if(j==l-1){
                    if(ck(s,i,j)){
                        vector<string> tmp;
                        tmp.push_back(s.substr(i,j-i+1));
                        mp[i].push_back(tmp);
                    }
                }else{
                    if(ck(s,i,j)){
                        vector<string> tmp;
                        tmp.push_back(s.substr(i,j-i+1));
                        for(auto &vs:mp[j+1]){
                            int len=vs.size();
                            for(int k=0;k<len;k++){
                                tmp.push_back(vs[k]);
                            }
                            mp[i].push_back(tmp);
                            for(int k=0;k<len;k++){
                                tmp.pop_back();
                            }
                        }
                    }
                }
            }
        }
        return mp[0];
    }
};