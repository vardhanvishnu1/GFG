class Solution {
public:

    bool solve(int i, int j, int n,
               vector<vector<int>>& mat,
               vector<vector<int>>& ans,
               vector<vector<int>>& dp) {

        if (i < 0 || j < 0 || i >= n || j >= n || mat[i][j] == 0)
            return false;

        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1;
            return true;
        }

        if (dp[i][j] == 0)
            return false;

        ans[i][j] = 1;

        for (int jump = 1; jump <= mat[i][j]; jump++) {

            // Right first
            if (solve(i, j + jump, n, mat, ans, dp)) {
                dp[i][j] = 1;
                return true;
            }

            // Then Down
            if (solve(i + jump, j, n, mat, ans, dp)) {
                dp[i][j] = 1;
                return true;
            }
        }

        ans[i][j] = 0;
        dp[i][j] = 0;  // no path from here
        return false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {

        int n = mat.size();

        if (mat[0][0] == 0)
            return {{-1}};

        vector<vector<int>> ans(n, vector<int>(n, 0));

        // -1 = unknown, 0 = no path, 1 = path exists
        vector<vector<int>> dp(n, vector<int>(n, -1));

        if (solve(0, 0, n, mat, ans, dp))
            return ans;

        return {{-1}};
    }
};