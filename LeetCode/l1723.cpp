class Solution {
public:
    int len;
    bool dfs(int pos,vector<int> &c,vector<int> &jobs,int k,int x){
        if(pos==len)return true;
        for(int i=0;i<k;i++){
            if(c[i]+jobs[pos]<=x){
                if(i!=0&&c[i-1]==0)continue;
                c[i]+=jobs[pos];
                if(dfs(pos+1,c,jobs,k,x))return true;
                c[i]-=jobs[pos];
            }
        }
        return false;
    }
    bool ck(vector<int> &jobs, int k, int x){
        vector<int> c(k);
        return dfs(0,c,jobs,k,x);
    } 
    int minimumTimeRequired(vector<int>& jobs, int k) {
        len=jobs.size();
        
        int l=0,r=0,mid;
        for(int i=0;i<len;i++){
            l=max(l,jobs[i]);
            r+=jobs[i];
        }
        sort(jobs.begin(), jobs.end(),greater<int>());
        while(l<r){
            mid=(l+r)/2;
            if(ck(jobs,k,mid)){
                r=mid;
            }else l=mid+1;
        }
        return l;
    }
};