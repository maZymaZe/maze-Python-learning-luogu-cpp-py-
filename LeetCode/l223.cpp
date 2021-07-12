class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a[4]={ay1,ay2,by1,by2};
        sort(a,a+4);
        int ty=0;
        for(int i=0;i<=2;i++){
            if((ay1<=a[i]&&a[i+1]<=ay2)||(by1<=a[i]&&a[i+1]<=by2))ty+=a[i+1]-a[i];
        }
        int b[4]={ax1,ax2,bx1,bx2};
        sort(b,b+4);
        int ans=0;
        for(int i=0;i<=2;i++){
            if(ax1<=b[i]&&b[i+1]<=ax2&&bx1<=b[i]&&b[i+1]<=bx2){
                ans+=ty*(b[i+1]-b[i]);
            }else if(ax1<=b[i]&&b[i+1]<=ax2){
                ans+=(b[i+1]-b[i])*(ay2-ay1);
            }else if(bx1<=b[i]&&b[i+1]<=bx2){
                ans+=(b[i+1]-b[i])*(by2-by1);
            }
        }
        return ans;
    }
};