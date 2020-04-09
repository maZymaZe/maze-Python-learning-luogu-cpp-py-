int cmp(const int&a,const int&b){
    return a>b;
}
int cnt=0,v[20],fl;
long long tot;
class Solution {
public:
    void dfs(long long s,vector<int>& nb,int w){
        if(s==0){cnt++;fl=1;}
        if(s>0&&w<nb.size()){
            for(int i=w;i<nb.size();i++){
                if(fl==0&&v[i]==0&&s>=nb[i]){
                    v[i]=1;
                    dfs(s-nb[i],nb,i+1);
                    if(fl==0)v[i]=0;
                }
            }
        }
    }
    bool makesquare(vector<int>& nums) {
        tot=0;cnt=0;
        memset(v,0,sizeof(v));
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size();i++){
            tot+=nums[i];
        }
        if(tot%4||tot<4)return false;
        tot/=4;
        for(int i=1;i<=4;i++){
            fl=0;
            dfs(tot,nums,0);
        }
        if(cnt==4)return true;
        return 0;
    }
};