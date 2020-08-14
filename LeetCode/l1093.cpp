class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double mi=255,ma=0,sum=0,zs=0,zws=0;
        int f=0,l=count.size(),t1=-1,t2=-1;
        long long cnt=0,p=0,tar;
        for(int i=0;i<l;i++){
            if(count[i]){
                if(i>ma)ma=i;
                if(i<mi)mi=i;
                if(count[i]>f)f=count[i],zs=i;
                sum+=1LL*count[i]*i;
                cnt+=count[i];
            }
        }
        if(cnt%2){
            tar=(cnt+1)/2;
            for(int i=0;i<l;i++){
                if(count[i]){
                    p+=count[i];
                    if(p>=tar){
                        zws=i;
                        break;
                    }
                }
            }
        }
        else{
            tar=cnt/2;
            for(int i=0;i<l;i++){
                if(count[i]){
                    p+=count[i];
                    if(p>=tar){
                        if(t1==-1)t1=i;
                    }
                    if(p>=tar+1){
                        if(t2==-1)t2=i;
                        break;
                    }
                }
            }
            zws=1.0*(t1+t2)/2;
        }
        return (vector<double>){mi,ma,1.0*sum/cnt,zws,zs};


    }
};