class Solution {
public:
    bool ck(vector<int> &w,int d, int x){
        int cd=1,u=x,l=w.size();
        for(int i=0;i<l;i++){
            if(u>=w[i])u-=w[i];
            else{
                if(x<w[i])return false;
                u=x-w[i];
                cd++;
                if(cd>d)return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int l=1,r=3e7,mid;
        while(l<r){
            mid=(l+r)/2;
            if(ck(weights,D,mid)){
                r= mid;
            }else l=mid+1;
        }
        return l;
    }
};