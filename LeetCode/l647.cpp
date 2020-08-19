class Solution {
public:
    int countSubstrings(string s) {
        int n;
        string t="$#";
        
        for(const char &c:s)t+=c,t+='#';
        n=t.size();
        t+='!';
        vector<int> f(n);
        int imax=0,rmax=0,ans=0;
        for(int i=1;i<n;i++){
            f[i]=(i<=rmax)?min(rmax-i+1,f[2*imax-i]):1;
            while(t[i+f[i]]==t[i-f[i]])++f[i];
            if(i+f[i]-1>rmax){
                rmax=i+f[i]-1;
                imax=i;
            }
            ans+=(f[i])/2;
        }
        return ans;
    }
};