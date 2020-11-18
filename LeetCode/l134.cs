public class Solution {
    public int CanCompleteCircuit(int[] gas, int[] cost) {
        int l=gas.Length,cnt=0,i=0;
        while(i<l){
            int sg=0,sc=0;
            cnt=0;
            while(cnt<l){
                int j=(i+cnt)%l;
                sg+=gas[j];
                sc+=cost[j];
                if(sc>sg)break;
                cnt++;
            }
            if(cnt==l)return i;
            else i=i+cnt+1;
        }
        return -1;
    }
}