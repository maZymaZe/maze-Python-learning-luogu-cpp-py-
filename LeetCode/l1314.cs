public class Solution {
    public int[][] MatrixBlockSum(int[][] mat, int K) {
        int n = mat.Length,m=mat[0].Length;
        int[,] presum=new int[n+1,m+1];
        int[][] ans=new int[n][];
        for(int i=0;i<n;i++){
            ans[i]=new int[m];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m; j++){
                presum[i,j]=presum[i-1,j]+presum[i,j-1]+mat[i-1][j-1]-presum[i-1,j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=( presum[Math.Min(n,i+K+1),Math.Min(m,j+K+1)]-presum[Math.Max(i-K,0),Math.Min(m,j+K+1)]-presum[Math.Min(n,i+K+1),Math.Max(j-K,0)]+presum[Math.Max(i-K,0),Math.Max(j-K,0)]);
            }
        }
        return ans;
    }
}