class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        int n = arr.size();

        sort(arr.begin(),arr.end());
        int ans = 0;

        // Iterate from the end
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] - arr[i - 1] < k) {
                ans += arr[i] + arr[i - 1];
                i--; // skip the paired element
            }
        }

        return ans;
    }
};