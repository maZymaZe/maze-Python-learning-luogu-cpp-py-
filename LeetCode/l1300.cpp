class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int l=0,r=0,mid,ans=0,ans1=0,ans2=0,ans3=0,p;
        for(int i:arr)r=max(r,i);
        while(l<r){
            mid=(l+r)/2,ans=0;
            for(auto i:arr){
                if(i>mid)ans+=mid;
                else ans+=i;
            }
            if(ans>=target)r=mid;
            else l=mid;

            if(l==r-1)break;
        }
        
        l=mid-1,r=mid,p=mid+1;
        for(auto i:arr){
            if(i>l)ans1+=l;
            else ans1+=i;
        }
        for(auto i:arr){
            if(i>r)ans2+=r;
            else ans2+=i;
        }
        for(auto i:arr){
            if(i>r)ans3+=p;
            else ans3+=i;
        }
        if(abs(ans1-target)<=abs(ans2-target))return (abs(ans1-target)<=abs(ans3-target))?l:p;
        if(abs(ans1-target)>abs(ans2-target))return (abs(ans2-target)<=abs(ans3-target))?r:p;
        return 0;
    }
};