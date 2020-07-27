class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0,p1=-1,p2=-1,cnt=0,tot=0,l=A.size();
        for(int i=0;i<l;i++){
            sum+=A[i];
        }
        if(sum%3)return false;
        sum/=3;
        for(int i=0;i<l;i++){
            tot+=A[i];
            if(tot==sum){
                p1=i;
                break;
            }
        }
        tot=0;
        for(int i=l-1;i>=0;i--){
            tot+=A[i];
            if(tot==sum){
                p2=i;
                break;
            }
        }
        if(p1>=0&&p2>=0&&p1+1<p2)return true;
        return false;
    }
};