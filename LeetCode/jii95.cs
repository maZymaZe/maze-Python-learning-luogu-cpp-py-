public class Solution {
    public int LongestCommonSubsequence(string text1, string text2) {
        int l1=text1.Length,l2=text2.Length;
        int[,] a=new int[1001,1001];
        a[0,0]=0;
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                if(text1[i]==text2[j]){
                    a[i+1,j+1]=a[i,j]+1;
                }else{
                    a[i+1,j+1]=Math.Max(a[i,j+1],a[i+1,j]);
                }
            }
        }
        return a[l1,l2];
    }
}