struct work{
    int d,m;
}w[10002];
int cmp(const work&a,const work&b){
    if(a.d<b.d)return 1;
    if(a.d==b.d&&a.m>b.m)return 1;
    return 0;
}
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans=0;
        int l=difficulty.size();
        for(int i=0;i<l;i++){
            w[i].d=difficulty[i];
            w[i].m=profit[i];
        }
        sort(w,w+l,cmp);
        int ma=0,p=-1,dd[10008],mm[10008];
        for(int i=0;i<l;i++){
            if(w[i].m>ma){
                p++;
                dd[p]=w[i].d;
                mm[p]=w[i].m;
                ma=w[i].m;
            }
        }
        for(int i=0;i<worker.size();i++){
            int ww=upper_bound(dd,dd+p,worker[i])-dd;
            if(ww!=0){
                if(ww==p){
                    if(worker[i]>=dd[p])ans+=mm[p];
                    else ans+=mm[p-1];
                }
                else ans+=mm[ww-1];
            }
            
        }
        return ans;
    }
};