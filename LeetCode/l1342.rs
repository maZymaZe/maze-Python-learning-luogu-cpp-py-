impl Solution {
    pub fn number_of_steps (num: i32) -> i32 {
        let mut cnt=0;
        let mut t=num;
        while t!=0{
            if t%2==0{
                t=t/2;
            }
            else{
                t=t-1;
            }
            cnt+=1;
        }
        return cnt;
    }
}