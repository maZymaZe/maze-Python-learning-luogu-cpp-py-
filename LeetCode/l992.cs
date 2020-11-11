public class Solution {
    public int[] SortArrayByParityII(int[] A) {
        int l=A.Length,p1=0,p2=1;
        int[] ans=new int[l];
        for(int i=0;i<l;i++){
            if(A[i]%2==0){
                ans[p1]=A[i];p1+=2;
            }else{
                ans[p2]=A[i];p2+=2;
            }
        }
        return ans;
    }
}