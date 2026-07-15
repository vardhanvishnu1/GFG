class Solution {
  public:
    int solve(int &ans,int n,int sum,vector<vector<int>>&dp){
        if(sum==0&&n==0) return 1;
        if(n==0) return 0;
        if(sum<0) return 0;
        if(dp[n][sum]!=-1) return dp[n][sum];
        int x = 0;
        for(int i=0;i<=9;i++){
             x += solve(ans,n-1,sum-i,dp);
        }
        return dp[n][sum] = x;
    }
    int countWays(int n, int sum) {
        // code here
        int ans = 0;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        for(int i=1;i<=9;i++){
            ans += solve(ans,n-1,sum-i,dp);
        }
        if(ans==0) return -1;
        return ans;
    }
};