class Solution {
public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();

        // up[i] = farthest index reachable from i while non-decreasing
        vector<int> up(n);
        up[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1])
                up[i] = up[i + 1];
            else
                up[i] = i;
        }

        // down[i] = leftmost index from which i can be reached while non-increasing
        vector<int> down(n);
        down[0] = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[i - 1])
                down[i] = down[i - 1];
            else
                down[i] = i;
        }

        vector<bool> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            ans.push_back(up[l] >= down[r]);
        }

        return ans;
    }
};