class Solution {
public:
    string originalDigits(string s) {
        int a[10]={0};
        for(int i=0;i<s.size();i++){
            if(s[i]=='z')a[0]++;
            if(s[i]=='o')a[1]++;
            if(s[i]=='w')a[2]++;
            if(s[i]=='h')a[3]++;
            if(s[i]=='u')a[4]++;
            if(s[i]=='f')a[5]++;
            if(s[i]=='x')a[6]++;
            if(s[i]=='v')a[7]++;
            if(s[i]=='g')a[8]++;
            if(s[i]=='i')a[9]++;
        }
        a[1]-=a[0]+a[2]+a[4];
        a[3]-=a[8];
        a[5]-=a[4];
        a[7]-=a[5];
        a[9]-=a[6]+a[5]+a[8];
        string ans="";
        for(int i=0;i<=9;i++){
            string t(a[i],i+'0');
            ans=ans+t;
        }
        return ans;
    }
};