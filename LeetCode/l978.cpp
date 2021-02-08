class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans=1,stat=0,l=arr.size(),s=1;
        for(int i=1;i<l;i++){
            if(stat==0){
                if(arr[i]==arr[i-1])s=1,stat=0;
                else if(arr[i]>arr[i-1])s+=1,stat=1;
                else s+=1,stat=2;
            }else if(stat==1){
                if(arr[i]==arr[i-1])s=1,stat=0;
                else if(arr[i]>arr[i-1])s=2,stat=1;
                else s+=1,stat=2;
            }else if(stat==2){
                if(arr[i]==arr[i-1])s=1,stat=0;
                else if(arr[i]>arr[i-1])s+=1,stat=1;
                else s=2,stat=2;
            }
            ans=max(ans,s);
        }
        return ans;
    }
};