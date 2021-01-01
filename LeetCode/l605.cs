public class Solution {
    public bool CanPlaceFlowers(int[] flowerbed, int n) {
        int l=flowerbed.Length;
        for(int i=0;i<l;i++){
            if(n==0)return true;
            if(flowerbed[i]==0&&(i==0||flowerbed[i-1]==0)&&(i==l-1||flowerbed[i+1]==0)){
                flowerbed[i]=1;
                n--;
            }
            if(n==0)return true;
        }
        return false;
    }
}