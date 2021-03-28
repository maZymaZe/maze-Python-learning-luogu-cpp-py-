class Solution {
public:
    bool isPerfectSquare(int num) {
        long long nu= num,l=0,r=100000;
        while(l<r){
            long long mid=(r+l)/2;
            if(mid*mid==nu)return true;
            else if(mid*mid>nu)r=mid;
            else l=mid+1;
        }
        return false;

    }
};