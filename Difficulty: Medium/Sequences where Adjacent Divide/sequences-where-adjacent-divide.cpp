class Solution {
  public:
  int solve(int prev,int n,int m,int idx,vector<vector<int>>&dp){
      if(idx==n) return 1;
      if(dp[idx][prev]!=-1) return dp[idx][prev];
      int ways = 0;
      for(int i=1;i<=m;i++){
          if((i%prev==0)||(prev%i==0)) ways+= solve(i,n,m,idx+1,dp);
      }
      return dp[idx][prev] = ways;
  }
    int count(int n, int m) {
        // code here
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return solve(1,n,m,0,dp);
    }
};