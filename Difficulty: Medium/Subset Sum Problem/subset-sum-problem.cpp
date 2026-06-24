class Solution {
  public:
    bool solve(int sum,int n,int idx,vector<int>& arr,vector<vector<int>>&dp){
        if(sum==0)  return true;
        if(idx>=n||sum<0)    return false;
        if(dp[sum][idx]!=-1) return dp[sum][idx];
        bool pick = solve(sum-arr[idx],n,idx+1,arr,dp);
        bool not_pick = solve(sum,n,idx+1,arr,dp);
        bool ans = pick|not_pick;
        return dp[sum][idx] = ans;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(10001,vector<int>(n,-1));
        sort(arr.begin(),arr.end());
        return solve(sum,n,0,arr,dp);
    }
};