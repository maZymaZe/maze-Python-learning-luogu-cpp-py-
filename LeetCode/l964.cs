public class Solution {
    public int LargestPerimeter(int[] A) {
        Array.Sort(A);
        int l=A.Length;
        for(int i=l-1;i>=2;i--){
            if(A[i-2]+A[i-1]>A[i])return A[i-2]+A[i-1]+A[i];
        }
        return 0;
    }
}