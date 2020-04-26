class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans=0,t;
        int a[1002]={0},c[2002]={0},y[1002],yp=0;
        for(int i=0;i<nums.size();i++)a[nums[i]]++;
        ans+=(long long)(a[1]-1)*(a[1]-2)*a[1]/6;
        t=a[1];
        a[1]=0;a[0]=0;
        c[0]=a[0];
        for(int i=1;i<=1000;i++)c[i]=c[i-1]+a[i];
        for(int i=1001;i<=2001;i++)c[i]=c[i-1];
        for(int i=1;i<=1000;i++)if(a[i])y[++yp]=i;
        for(int i=1;i<=yp;i++)ans+=(a[y[i]]-1)*a[y[i]]/2*t;
        for (int i = 1; i <= yp; i++) {
        for (int j = i; j <= yp; j++) {
            if (i != j) {
                ans += a[y[i]] * a[y[j]] * (c[y[i] + y[j] - 1] - c[y[j]]) +
                       a[y[i]] * a[y[j]] * (a[y[j]] - 1) / 2;
            } else {
                ans +=
                    (long long)(a[y[i]] - 1) * (a[y[i]] - 2) * a[y[i]] / 6 +
                    (c[2 * y[i] - 1] - c[y[i]]) * a[y[i]] * (a[y[i]] - 1) / 2;
            }
        }
    }
        return ans;
    }
};