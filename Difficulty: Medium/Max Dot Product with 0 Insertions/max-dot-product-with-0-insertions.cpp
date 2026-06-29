// class Solution {
//   public:
//   int solve(int i,int j,int n,int m,vector<int>& a, vector<int>& b,vector<vector<int>>&dp){
//       if(j==m) return 0;
//       if(i==n) return INT_MAX;
//       if(m-j>n-i) return INT_MAX;
//       if(dp[i][j]!=-1) return dp[i][j];
//       int ans = solve(i+1, j+1, n, m, a, b, dp);
//       int take = INT_MIN;
//       if(ans != INT_MAX)
//       take = a[i] * b[j] + ans;
//       int not_take = solve(i+1,j,n,m,a,b,dp);
//       return dp[i][j] = max(take,not_take);
//   }
//     int maxDotProduct(vector<int>& a, vector<int>& b) {
//         // code here
//         int n = a.size();
//         int m = b.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(0,0,n,m,a,b,dp);
//     }
// };
class Solution {
public:
    const int INF = 1e9;

    int solve(int i, int j, vector<int>& a, vector<int>& b,
              vector<vector<int>>& dp) {

        int n = a.size(), m = b.size();

        if (j == m) return 0;          // all elements of b are used
        if (i == n) return -INF;       // impossible
        if (m - j > n - i) return -INF; // not enough elements left

        if (dp[i][j] != -1)
            return dp[i][j];

        int take = a[i] * b[j] + solve(i + 1, j + 1, a, b, dp);
        int skip = solve(i + 1, j, a, b, dp);

        return dp[i][j] = max(take, skip);
    }

    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, a, b, dp);
    }
};