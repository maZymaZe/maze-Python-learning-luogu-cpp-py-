int n,m;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size(),m=nums2.size();
        if((n+m)&1)return f(nums1,nums2,(n+m+1)/2);
        else return 1.0*(f(nums1,nums2,(n+m)/2)+f(nums1,nums2,(n+m+2)/2))/2.0;
    }
    int f(vector<int>& nums1, vector<int>& nums2,int k){
        int i1=0,i2=0;
        while(1){
            if(i1==n)return nums2[i2+k-1];
            if(i2==m)return nums1[i1+k-1];
            if(k==1)return min(nums1[i1],nums2[i2]);
            int n1=min(i1+k/2-1,n-1);
            int n2=min(i2+k/2-1,m-1);
            if(nums2[n2]<nums1[n1]){
                k-=n2-i2+1;
                i2=n2+1;
            }
            else{
                k-=n1-i1+1;
                i1=n1+1;
            }
        }
    }
};