struct pr{int a,b;};
class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pr> v;
        int l=height.size();
        for(int i=0;i<l;i++)v.push_back({height[i],weight[i]});
        sort(v.begin(),v.end(),[](const pr& a,const pr& b){return a.a<b.a||(a.a==b.a&&a.b>b.b);});
        int p=0;
        vector<int> t(l+1);
        for(int i=0;i<l;i++){
            if(p==0)t[++p]=v[i].b;
            else{
                if(v[i].b>t[p])t[++p]=v[i].b;
                else if(v[i].b<=t[1])t[1]=v[i].b;
                else{
                    int w=lower_bound(t.begin()+1,t.begin()+1+p,v[i].b)-t.begin();
                    t[w]=v[i].b;
                }
            }
        }
        return p;
    }
};