class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        int totalSum = 0;
        for (int x : arr) totalSum += x;

        // Check if target is possible:
        // 1. Target cannot be greater than the total sum.
        // 2. (target + totalSum) must be even (as derived in the formula).
        if (abs(target) > totalSum || (target + totalSum) % 2 != 0) {
            return 0;
        }

        int s1 = (target + totalSum) / 2;
        int n = arr.size();

        // dp[i] will store the number of ways to get sum 'i'
        vector<int> dp(s1 + 1, 0);
        
        // Base case: There is 1 way to make a sum of 0 (by choosing nothing)
        dp[0] = 1;

        for (int num : arr) {
            // We iterate backwards to ensure we don't use the same element twice
            for (int j = s1; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[s1];
    }
};