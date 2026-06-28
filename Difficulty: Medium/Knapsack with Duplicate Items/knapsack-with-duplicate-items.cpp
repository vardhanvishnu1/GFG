class Solution {
  public:
  int solve(int capacity,int idx,vector<int>& val, vector<int>& wt,vector<vector<int>>&dp){
    if(idx==val.size()) return 0;
    if(dp[idx][capacity]!=-1) return dp[idx][capacity];
    int take = 0;
    if(wt[idx]<=capacity)
        take += val[idx] + solve(capacity-wt[idx],idx,val,wt,dp);
    int skip = solve(capacity,idx+1,val,wt,dp);
    return dp[idx][capacity] = max(take,skip);
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return solve(capacity,0,val,wt,dp);
    }
};