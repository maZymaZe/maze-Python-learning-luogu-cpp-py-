class Solution {
   public:
    int maximumLength(string s) {
        vector<int> c[26];
        char pre = s[0];
        int l = s.size(), t = 1;
        for (int i = 1; i < l; i++) {
            if (s[i] == pre)
                t++;
            else {
                c[pre - 'a'].push_back(t);
                pre = s[i], t = 1;
            }
        }
        c[pre - 'a'].push_back(t);
        int ans=-1;
        for(int i=0;i<26;i++){
            int sz=c[i].size();
            sort(c[i].begin(),c[i].end(),greater<int>());
            if(sz>0&&c[i][0]>2){
                ans=max(ans,c[i][0]-2);
            }
            if(sz>1&&c[i][0]>c[i][1]){
                ans=max(ans,c[i][1]);
            }
            if(sz>1&&c[i][0]==c[i][1]&&c[i][0]>1){
                ans=max(ans,c[i][1]-1);
            }
            if(sz>2){
                ans=max(ans,c[i][2]);
            }
        }
        return ans;
    }
};