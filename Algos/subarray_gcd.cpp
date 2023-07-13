vector<long long> A;
vector<unordered_map<int,int>> dp; // dp[i,j] -> max len of subarray ending at i having gcd j
void preprocess(){
    dp[0][A[0]] = 0;
    for(int i=1;i<A.size();i++){
        dp[i][A[i]] = 0;
        for(auto x:dp[i-1]){
            int new_gcd = gcd(x.first,A[i]);
            dp[i][new_gcd] = max(dp[i][new_gcd],x.second+1);
        }
    }
}
