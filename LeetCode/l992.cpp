class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int len= A.size(),p=0,n=0,ans=0,q=0,t=1;
        vector<int> cnt(len+1);
        while(p<len&&n<K){
            cnt[A[p]]++;
            if(cnt[A[p]]==1)n++;
            p++;
        }
        if(p==len&&n!=K)return ans;
        while(cnt[A[q]]>1){
            cnt[A[q]]--;
            q++;
            t++;
        }
        ans+=t;
        for(int i=p;i<len;i++){
            if(cnt[A[i]]){
                cnt[A[i]]++;
                while(cnt[A[q]]>1){
                    cnt[A[q]]--;
                    q++;
                    t++;
                }
                ans+=t;
            }else{
                cnt[A[i]]++;
                n++;
                while(n>K){
                    cnt[A[q]]--;
                    if(cnt[A[q]]==0)n--;
                    q++;
                }
                t=1;
                while(cnt[A[q]]>1){
                    cnt[A[q]]--;
                    q++;
                    t++;
                }
                ans+=t;
            }
        }
        return ans;
    }
};