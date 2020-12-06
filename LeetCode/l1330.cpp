class Solution {
public:
    int gma(vector<int> &v){
        int res=INT_MIN;
        for(int i:v)res=max(res,i);
        return res;
    }
    int gmi(vector<int> &v){
        int res=INT_MAX;
        for(int i:v)res=min(res,i);
        return res;
    }
    int maxValueAfterReverse(vector<int>& nums) {
        int res=0,n=nums.size();
        for(int i=1;i<n;i++)res+=abs(nums[i]-nums[i-1]);
        int maxv=0;
        for(int i=0;i<n;i++){
            if(i!=n-1)maxv=max(maxv,abs(nums[0]-nums[i+1])-abs(nums[i]-nums[i+1]));
            if(i!=0)maxv=max(maxv,abs(nums[i-1]-nums[n-1])-abs(nums[i]-nums[i-1]));
        }
        int dx[4]={1,1,-1,-1},dy[4]={-1,1,-1,1};
        for(int i=0;i<4;i++){
            vector<int> v1,v2;
            for(int j=0;j<n-1;j++){
                int a=dx[i]*nums[j];
                int b=dy[i]*nums[j+1];
                int cur=abs(nums[j+1]-nums[j]);
                v1.push_back(a+b-cur);
                v2.push_back(a+b+cur);
            }
            int a=gma(v1);
            int b=gmi(v2);
            maxv=max(maxv,a-b);
        }
        return maxv+res;
    }
};