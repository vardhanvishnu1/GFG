class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<bool>dp(sum+1,0);
        dp[0] = 1;
        for(auto el : arr){
            if(el>sum) continue;
            for(int i = sum;i>=el;i--){
                dp[i] = dp[i] || dp[i-el];
            }
        }
        return dp[sum]>0;
    }
};