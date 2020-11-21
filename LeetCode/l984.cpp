class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ans;
        if(A>=B){
            while(A>0||B>0){
                if(A>0)ans+="a",A--;
                if(A>0)ans+="a",A--;
                if(B>1&&(B-2)>=((A+1)/2)-1)ans+="bb",B-=2;
                else if(B>0)ans+="b",B--;
            }
        }else{
            while(A>0||B>0){
                if(B>0)ans+="b",B--;
                if(B>0)ans+="b",B--;
                if(A>1&&(A-2)>=((B+1)/2)-1)ans+="aa",A-=2;
                else if(A>0)ans+="a",A--;
            }
        }
        return ans;
    }
};