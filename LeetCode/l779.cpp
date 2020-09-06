class Solution {
public:
    int kthGrammar(int N, int K) {
        int ans=0;
        while(N>1){
            if(K>(1<<(N-2)))ans^=1;
            K=(K-1)%(1<<(N-2))+1;
            N--;
        }
        return ans;
    }
};