class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        
        vector<int> B;
        while(K)B.push_back(K%10),K/=10;
        if(B.empty())B.push_back(0);
        reverse(B.begin(),B.end());
        if(A.size()<B.size())swap(A,B);
        int p=A.size()-1,carry=0;
        for(int i=B.size()-1;i>=0;i--){
            A[p]+=B[i];
            if(p==0&&A[p]>=10){
                carry=1;
                A[p]%=10;
            }else if(p!=0&&A[p]>=10){
                A[p]%=10;
                A[p-1]++;
            }
            p--;
        }
        for(int i=p;i>=0;i--){
            if(i==0&&A[i]>=10){
                carry=1;
                A[i]%=10;
            }else if(i!=0&&A[i]>=10){
                A[i]%=10;
                A[i-1]++;
            }
        }

        if(!carry)return A;
        vector<int> C;
        C.push_back(1);
        for(int i:A)C.push_back(i);
        return C;
    }
};