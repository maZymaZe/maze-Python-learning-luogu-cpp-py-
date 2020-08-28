class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int l=s.size();
        if(l<k+(1<<k)-1)return false;
        vector<int> v(1<<k);
        int t=0;
        for(int i=0;i<k;i++){
            t=(t<<1)+s[i]-'0';
        }
        v[t]++;
        for(int i=0;i<l-k;i++){
            t-=((s[i]-'0')<<(k-1));
            t<<=1;
            t+=(s[i+k]-'0');
            v[t]++;
        }
        int p=1<<k;
        for(int i=0;i<p;i++)if(!v[i])return false;
        return true;
    }
};