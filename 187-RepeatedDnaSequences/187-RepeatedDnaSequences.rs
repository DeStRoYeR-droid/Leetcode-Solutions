// Last updated: 13/07/2026, 22:24:41
use std::collections::HashMap;

impl Solution {
    pub fn find_repeated_dna_sequences(s: String) -> Vec<String> {
        if s.len() < 10 {
            return Vec::new();
        }

        let mut result: Vec<String> = Vec::new();
        let mut freq: HashMap<&[u8], u32> = HashMap::new();

        for window in s.as_bytes().windows(10) {
            *freq.entry(window).or_insert(0) += 1;
        }

        for (bytes, &val) in freq.iter(){
            if (val >= 2){
                result.push(String::from_utf8(bytes.to_vec()).unwrap());
            }
        }
        return result;
    }
}