public class Solution {
    public bool SearchMatrix(int[,] matrix, int target) {
        int n=matrix.GetLength(0)-1,m=0,l=matrix.GetLength(1);
        while(n>=0&&m<l){
            if(matrix[n,m]==target)return true;
            else if(matrix[n,m]<target)m++;
            else n--;
        }
        return false;
    }
}