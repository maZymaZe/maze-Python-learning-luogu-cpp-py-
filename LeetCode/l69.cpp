class Solution {
public:
    int mySqrt(int x) {
        if(x<2)return x;
        int l=1,r=x/2+1,mid;
        while(r>l){
            mid=l+(r-l)/2;
            if(1LL*mid*mid>x)r=mid;
            else l=mid;
            if(r==l+1)return l;
        }
        return l;
    }
};