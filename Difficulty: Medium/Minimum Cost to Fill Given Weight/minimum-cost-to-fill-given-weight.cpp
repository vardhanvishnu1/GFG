class Solution {
  public:
  

    int minimumCost(vector<int> &cost, int w) {
        // code here
         const int INF = 1e9;

    vector<int> dp(w + 1, INF);
    dp[0] = 0;

    int n = cost.size();

    for (int i = 1; i <= w; i++) {
        for (int j = 0; j < n; j++) {
            int packetWeight = j + 1;

            if (cost[j] != -1 && packetWeight <= i) {
                dp[i] = min(dp[i],
                            dp[i - packetWeight] + cost[j]);
            }
        }
    }

    return (dp[w] == INF) ? -1 : dp[w];
    }
};
