class Solution {
  public:
    
    unordered_map<int,long long> dp;
    
    long long solve(int n){
        
        if(n == 0) return 0;
        
        if(dp.count(n))
            return dp[n];
        
        long long breakSum =
            solve(n/2) +
            solve(n/3) +
            solve(n/4);
        
        return dp[n] = max((long long)n, breakSum);
    }
    
    int maxSum(int n) {
        return solve(n);
    }
};