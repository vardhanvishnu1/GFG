class Solution {
  public:
  int solve(int target,int n,int idx,vector<int>& arr,vector<vector<int>>&dp){
      if(target<0) return false;
      if(idx==n){
         return target == 0;
      }
      if(dp[target][idx]!=-1) return dp[target][idx];
      int take = solve(target-arr[idx],n,idx+1,arr,dp);
      int not_take = solve(target,n,idx+1,arr,dp);
      return dp[target][idx] = take+not_take;
        
  }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int ans =0;
        vector<vector<int>>dp(target+1,vector<int>(n,-1));
        return solve(target,n,0,arr,dp);
    }
};