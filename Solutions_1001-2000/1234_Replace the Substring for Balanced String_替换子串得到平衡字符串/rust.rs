use std::collections::HashMap;

impl Solution {
    pub fn balanced_string(s: String) -> i32 {
        let target = s.len() / 4; 
        let ss : Vec<char> = s.chars().collect();

        let mut counter = vec![0; 4];
        for c in &ss {
            if *c == 'Q' {counter[0] += 1;}
            if *c == 'W' {counter[1] += 1;}
            if *c == 'E' {counter[2] += 1;}
            if *c == 'R' {counter[3] += 1;}
        }
        if counter[0] == target && counter[1] == target && counter[2] == target { return 0; }
        counter[0] = if counter[0] <= target {0} else {counter[0] - target};
        counter[1] = if counter[1] <= target {0} else {counter[1] - target};
        counter[2] = if counter[2] <= target {0} else {counter[2] - target};
        counter[3] = if counter[3] <= target {0} else {counter[3] - target};

        let mut ret = ss.len();
        let mut l = 0;
        let mut r = 0;
        let mut window = vec![0; 4];
        let mut inc = true;
        while l < ss.len() {
            if (inc) {
                if r == ss.len() { break; }
                if ss[r] == 'Q' { window[0] += 1; }
                if ss[r] == 'W' { window[1] += 1; }
                if ss[r] == 'E' { window[2] += 1; }
                if ss[r] == 'R' { window[3] += 1; }
                r += 1;
                if window[0] >= counter[0] && window[1] >= counter[1]
                && window[2] >= counter[2] && window[3] >= counter[3] {
                    inc = false;
                    if r - l < ret { ret = r - l; }
                }
            } else {
                if ss[l] == 'Q' { window[0] -= 1; }
                if ss[l] == 'W' { window[1] -= 1; }
                if ss[l] == 'E' { window[2] -= 1; }
                if ss[l] == 'R' { window[3] -= 1; }
                l += 1;
                if window[0] >= counter[0] && window[1] >= counter[1]
                && window[2] >= counter[2] && window[3] >= counter[3] {
                    inc = false;
                    if r - l < ret { ret = r - l; }
                } else {
                    if r == ss.len() { break; }
                    else { inc = true; }
                }
            }
        }
        return ret as i32;
    }
}