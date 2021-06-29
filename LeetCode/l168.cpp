class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<int> v;
        while(columnNumber){
            if(columnNumber%26==0){
                v.push_back(26);
                columnNumber/=26;
                columnNumber--;
            }else{
                v.push_back(columnNumber%26); 
                columnNumber/=26;
            }
        }
        int l=v.size();
        string ans;
        for(int i=l-1; i>=0; i--){
            ans+=v[i]+'A'-1;
        }
        return ans;
    }
};