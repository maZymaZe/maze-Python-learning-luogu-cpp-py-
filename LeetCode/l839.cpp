class Solution {
public:
    int l,ans=0;
    vector<int> f;
    int ff(int x) { return f[x] == x ? x : f[x] = ff(f[x]); }
    bool ck(string&a,string&b){
        if(a.size()!=b.size())return false;
        int len=a.size();
        if(a==b)return true;
        int difs=0,dif[3];
        for(int i=0; i < len; i++){
            if(a[i]!=b[i])dif[difs++]=i;
            if(difs==3)break;
        }
        if(difs!=2)return false;
        return a[dif[0]]==b[dif[1]]&&a[dif[1]]==b[dif[0]];
    }
    int numSimilarGroups(vector<string>& strs) {
        l= strs.size();
        f.resize(l);
        for(int i=0; i < l; i++)f[i]=i;
        for(int i=0; i < l; i++){
            for(int j=i+1; j < l; j++){
                int fi=ff(i),fj=ff(j);
                if(fi != fj){
                    if(ck(strs[i],strs[j]))f[fi]=fj;
                }
            }
        }
        for(int i=0;i<l;i++)if(f[i]==i)ans++;
        return ans;
    }
};