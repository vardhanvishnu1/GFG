class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        int total = accumulate(arr.begin(), arr.end(), 0);

        if (diff > total) return 0;
        if ((total + diff) % 2) return 0;

        int target = (total + diff) / 2;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int x : arr) {
            for (int j = target; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }

        return dp[target];
    }
};