class Solution {
public:
    unordered_map<int,int> mp[3];
    int hs(int l,int res){return l*500+res;}
    int work(vector<int> &slices, int l,int r,int res,int gp){
        if (res == 0)
        return 0;
        if((r-l)/2+1<res)return 0;
        int ns=hs(l,res);
        if(mp[gp].count(ns))return mp[gp][ns];
        int ret=slices[l],ma=0;
        for(int i=l+2;i<=r;i++){
            if((r-i)/2+1>=res-1){
                ma=max(ma,work(slices,i,r,res-1,gp));
            }else break;
        }
        ret+=ma;
        if(l+1<=r&&(r-l-1)/2+1>=res)ret=max(ret,work(slices,l+1,r,res,gp));
        return mp[gp][ns]=ret;
    }
    int maxSizeSlices(vector<int>& slices) {
        int l=slices.size();
        int n=l/3;
        int ans1=slices[0]+work(slices,2,l-2,n-1,0);
        int ans2=slices[l-1]+work(slices,1,l-3,n-1,1);
        int ans3=work(slices,1,l-2,n,2);
        return max(ans3,max(ans2,ans1));
    }
};