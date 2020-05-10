struct worker{
    int q,w;
}e[10002];
int cmp(const worker& a,const worker& b){
    return a.q<b.q;
}
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int l=wage.size(),f;
        for(int i=0;i<l;i++){
            e[i].q=quality[i];e[i].w=wage[i];
        }
        sort(e,e+l,cmp);
        double st,mi=(double)2000000000000,tot;
        for(int i=0;i<l;i++){
            f=1;
            st=1.0*e[i].w/e[i].q;
            tot=e[i].w;
            int j=0,cnt=1;
            while(cnt<K&&j<l){
                if(i==j){
                    j++;continue;
                }
                if(st*e[j].q>=e[j].w)cnt++,tot+=st*e[j].q;
                j++;
            }
            if(cnt==K&&tot<mi)mi=tot;
        }
        return mi;
    }
};