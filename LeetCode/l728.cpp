public class Solution {
    public IList<int> SelfDividingNumbers(int left, int right) {
        IList<int> result = new List<int>();
        bool b;
        for(int i = left;i<=right;i++) {
            int t=i;
            b=true;
            while(t!=0){
                if(t%10!=0&&i%(t%10)==0){
                    t/=10;
                }else{
                    b=false;break;
                }
            }
            if(b)result.Add(i);
        }
        return result;
    }
}