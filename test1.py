def solve_case(E, K):
    MOD = 998244353
    n = len(E)
    dp = [0] * (n + 1)
    dp[0] = 1
    E_list = list(E)
    total_q = E.count('?')
    possible_digits = ['1', '2']

    question_positions = [i for i, ch in enumerate(E) if ch == '?']
    num_q = len(question_positions)
    
    total_combinations = 2 ** num_q 

    K -= 1  
    for i in range(num_q):
        idx = question_positions[i]
        combinations_per_digit = 2 ** (num_q - i - 1)
        if K < combinations_per_digit:
            E_list[idx] = '2' 
        else:
            K -= combinations_per_digit
            E_list[idx] = '1'  

    uncorrupted_E = ''.join(E_list)

    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(1, n + 1):
        if E_list[i - 1] != '0':
            dp[i] += dp[i - 1]
        if i >= 2:
            two_digit = int(E_list[i - 2] + E_list[i - 1])
            if 10 <= two_digit <= 26 and E_list[i - 2] != '0':
                dp[i] += dp[i - 2]
        dp[i] %= MOD

    num_decodings = dp[n]
    return uncorrupted_E, num_decodings

def main():
    MOD = 998244353
    T = int(input())
    for case_num in range(1, T + 1):
        line = input().strip()
        if not line:
            line = input().strip()
        E, K = line.split()
        K = int(K)
        uncorrupted_E, num_decodings = solve_case(E, K)
        if uncorrupted_E is None:
            print(f"Case #{case_num}: IMPOSSIBLE")
        else:
            print(f"Case #{case_num}: {uncorrupted_E} {num_decodings % MOD}")

if __name__ == "__main__":
    main()
