class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return string();
        int l=strs[0].size(),r=strs.size();
        for(int i=0;i<l;i++){
            char m=strs[0][i];
            for(int j=1;j<r;j++){
                if(i==strs[j].size()||strs[j][i]!=m){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};