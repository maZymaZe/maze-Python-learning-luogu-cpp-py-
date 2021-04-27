class Solution {
public:
    vector<int> c;
    int lim;
    int lowbit(int x){
        return (-x)&x;
    }
    void upd(int pos,int x){
        while(pos<=lim){
            c[pos]+=x;
            pos+=lowbit(pos);
        }
    }
    int query(int pos){
        int res=0;
        while(pos){
            res+=c[pos];
            pos-=lowbit(pos);
        }
        return res;
    }
    vector<int> processQueries(vector<int>& queries, int m) {
        int n=queries.size();
        lim=n+m+10;
        c.resize(lim+2);
        vector<int> ps(m+1);
        for(int i=1;i<=m;i++){
            ps[i]=n+i;
            upd(n+i,1);
        }
        vector<int> ans;
        for(int i=0;i<n; i++){
            upd(ps[queries[i]],-1);
            ans.push_back(query(ps[queries[i]]));
            ps[queries[i]]=n-i;
            upd(ps[queries[i]],1);
        }
        return ans;
    }
};