public class Solution {
    public int CountBalls(int lowLimit, int highLimit) {
        int[] cnt = new int[50];
        for(int i=lowLimit;i<=highLimit;i++){
            int c=0,t=i;
            while(t!=0){
                c+=t%10;
                t/=10;
            }
            cnt[c]++;
        }
        int ma=1;
        for(int i=0;i<50;i++){
            if(cnt[i]>ma)ma=cnt[i];
        }
        return ma;
    }
}