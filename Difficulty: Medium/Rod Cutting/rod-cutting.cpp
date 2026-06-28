class Solution {
public:
    int cutRod(vector<int> &price) {
        int n = price.size();

        vector<int> wt(n);
        for (int i = 0; i < n; i++)
            wt[i] = i + 1;

        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = wt[i]; j <= n; j++) {
                dp[j] = max(dp[j], price[i] + dp[j - wt[i]]);
            }
        }

        return dp[n];
    }
};