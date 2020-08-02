struct pr{
    int n,cnt;
};
bool cmp(const pr&a,const pr&b){
    return a.cnt>b.cnt||(a.cnt==b.cnt&&a.n<b.n);
}
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        pr p[10005]={(pr){0,0}};
        for(int i=1;i<=10000;i++)p[i].n=i;
        int l=barcodes.size();
        for(int i=0;i<l;i++)p[barcodes[i]].cnt++;
        sort(p,p+10002,cmp);
        vector<int> ret(l);
        int t=0;
        for(int i=0;i<l;i+=2){
            if(!p[t].cnt)t++;
            p[t].cnt--;
            ret[i]=p[t].n;
        }
        for(int i=1;i<l;i+=2){
            if(!p[t].cnt)t++;
            p[t].cnt--;
            ret[i]=p[t].n;
        }
        return ret;
    }
};