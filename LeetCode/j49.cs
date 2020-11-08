public class Solution {
    public int NthUglyNumber(int n) {
         int[] a= new int[2000];
        a[0]=1;
        int p2=0,p3=0,p5=0;
        for(int i=1;i<n;i++){
            a[i]=Math.Min(Math.Min(a[p2]*2,a[p3]*3),a[p5]*5);
            if(a[i]==a[p2]*2)p2++;
            if(a[i]==a[p3]*3)p3++;
            if(a[i]==a[p5]*5)p5++;
        }
        return a[n-1];
    }
}