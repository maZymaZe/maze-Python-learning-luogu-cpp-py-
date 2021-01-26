class Solution {
public:
    int l;
    int cnt[10][10],t1,t2,ans=0;
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
       l=dominoes.size();
       for(int i=0;i<l;i++){
           t1=dominoes[i][0],t2=dominoes[i][1];
           if(t2<t1)swap(t2,t1);
           cnt[t1][t2]++;
       }
       for(int i=0;i<=9;i++){
           for(int j=i;j<=9;j++){
               ans+=cnt[i][j]*(cnt[i][j]-1)/2;
           }
       }
       return ans;
    }
};