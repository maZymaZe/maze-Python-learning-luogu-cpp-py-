impl Solution {
    pub fn min_cost_to_move_chips(chips: Vec<i32>) -> i32 {
        let mut c=0;
        for i in 0..chips.len() {
            if(chips[i]%2==0){
                c+=1;
            }
        }
        return core::cmp::min(chips.len() as i32-c,c);
    }
}