struct pr{
    int a, b;
    bool operator <(const pr& x)const{
        return a > x.a;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        string ans;
        pr p[300]={0};
        int l=s.size();
        for(int i=0;i<l;i++){
            p[s[i]].a++,p[s[i]].b=s[i];
        }
        sort(p,p+300);
        for(int i=0;i<300;i++){
            if(p[i].a)ans+=string(p[i].a,(char)p[i].b);
        }   
        return ans;
    }
};
