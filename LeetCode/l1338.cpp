struct pr{
    int p,c;
    bool operator<(const pr&x){ return c>x.c;}
};
class Solution {
public:
    pr a[100002];
    int minSetSize(vector<int>& arr) {
        int l=arr.size();
        for(int i=0; i<l;i++)a[arr[i]].c++;
        sort(a,a+100001);
        int cnt=0,ans = 0,p=0;
        while(2*cnt<l){
            cnt+=a[p].c;ans++;p++;
        }
        return ans;
    }
};