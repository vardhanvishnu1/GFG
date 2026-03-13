class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        if (n == 0) return 0;

        sort(arr.begin(), arr.end());

        int ans = 1;
        int cnt = 1;
        int lastSmaller = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] == lastSmaller + 1) {
                // It's consecutive!
                cnt++;
                lastSmaller = arr[i];
            } 
            else if (arr[i] != lastSmaller) {
                // It's a gap (and not a duplicate)
                ans = max(ans, cnt);
                cnt = 1;
                lastSmaller = arr[i];
            }
            // Note: if arr[i] == lastSmaller, we do nothing (skip duplicate)
        }
        
        return max(ans, cnt);
    }
};