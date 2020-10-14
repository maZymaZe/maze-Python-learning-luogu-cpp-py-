class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        int l=A.size();
        if (l==0) return{};
        int re[26]={0},t[26]={0};
        for(int i=A[0].size()-1;i>=0;i--){
            re[A[0][i]-'a']++;
        }
        for(int i=1;i<l;i++){
            memset(t,0,sizeof(t));
            for(int j=A[i].size()-1;j>=0;j--){
                t[A[i][j]-'a']++;
            }
            for(int j=0;j<26;j++){
                re[j]=min(re[j],t[j]);
            }
        }
        for(int j=0;j<26;j++){
            for(int i=0;i<re[j];i++){
                ans.push_back(string(1,j+'a'));
            }
        }
        return ans;
    }
};