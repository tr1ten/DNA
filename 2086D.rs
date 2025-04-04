use std::io::{self, BufRead, BufReader, Write};

const MOD: i64 = 998244353;
const N: usize = 14 * 5 * 100_000 + 5; // 7_000_005

fn precompute() -> (Vec<i64>, Vec<i64>, Vec<i64>) {
    let mut fact = vec![0i64; N];
    let mut inv = vec![0i64; N];
    let mut finv = vec![0i64; N];
    fact[0] = 1;
    for i in 1..N {
        fact[i] = fact[i - 1] * (i as i64) % MOD;
    }
    inv[1] = 1;
    for i in 2..N {
        let i_val = i as i64;
        inv[i] = (MOD - MOD / i_val) * inv[(MOD % i_val) as usize] % MOD;
    }
    finv[0] = 1;
    finv[1] = 1;
    for i in 2..N {
        finv[i] = inv[i] * finv[i - 1] % MOD;
    }
    (fact, inv, finv)
}

fn get_subset_sums(a: &[i64]) -> Vec<i64> {
    let len = a.len();
    let total = 1 << len;
    let mut res = Vec::with_capacity(total);
    for mask in 0..total {
        let mut sum = 0;
        let mut m = mask;
        while m != 0 {
            let j = m.trailing_zeros() as usize;
            sum += a[j];
            m &= m - 1;
        }
        res.push(sum);
    }
    res
}
fn solve(a: &[i64], target: i64) -> i64 {
    let n = a.len();
    let mid = n / 2;
    let left = get_subset_sums(&a[..mid]);
    let right = get_subset_sums(&a[mid..]);

    let mut left_sorted = left;
    let mut right_sorted = right;
    left_sorted.sort();
    right_sorted.sort();

    let mut ans = 0;
    for &l_sum in left_sorted.iter() {
        let req = target - l_sum;
        let low = right_sorted.partition_point(|&y| y < req);
        let high = right_sorted.partition_point(|&y| y <= req);
        ans += (high - low) as i64;
    }
    ans
}

fn main() {
    let (fact, _inv, finv) = precompute();
    let stdin = io::stdin();
    let mut reader = BufReader::new(stdin.lock());
    let mut t_line = String::new();
    reader.read_line(&mut t_line).unwrap();
    let t: usize = t_line.trim().parse().unwrap();

    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    for _ in 0..t {
        let mut input_line = String::new();
        reader.read_line(&mut input_line).unwrap();
        let c: Vec<i64> = input_line
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();

        let mut a = Vec::new();
        for &x in c.iter().take(26) {
            if x != 0 {
                a.push(x);
            }
        }
        
        let s_total: i64 = a.iter().sum();
        let target = s_total / 2;
        let cnt = solve(&a, target);
        let mut ans = cnt % MOD;
        ans = ans * fact[target as usize] % MOD * fact[(s_total - target) as usize] % MOD;
        let mut den = 1;
        for &x in &a {
            den = den * finv[x as usize] % MOD;
        }
        ans = ans * den % MOD;
        writeln!(out, "{}", ans).unwrap();
    }
}
