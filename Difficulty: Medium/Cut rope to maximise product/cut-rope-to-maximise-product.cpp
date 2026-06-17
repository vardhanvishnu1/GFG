class Solution {
  public:
    int maxProduct(int n) {
        // code here
       vector<int>dp(n+1,0);
       dp[0] = 0;
       dp[1] =1;
       dp[2] =1;
    //   dp[3]= 2;
    //   dp[4] = 4;
    //   dp[5]=6;
       for(int i=3;i<n+1;i++){
            for(int j = 1;j<i;j++){
                dp[i] = max(dp[i],max(j*(i-j),dp[i-j]*j));
            }
       }
       return dp[n];
    } 
};