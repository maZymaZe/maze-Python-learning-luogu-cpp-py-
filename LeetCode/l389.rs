impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        (t.as_bytes().iter().fold(0,|sum,x|sum + x)-s.as_bytes().iter().fold(0,|sum,x|sum+x)) as char
    }
}