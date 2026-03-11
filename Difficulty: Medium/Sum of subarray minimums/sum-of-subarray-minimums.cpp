class Solution {
  public:
    int sumSubMins(vector<int> &a) {
        int n = a.size();
        stack<int> s;
        // dp[i] will store the sum of minimums of all subarrays starting at index i
        vector<unsigned int> dp(n, 0); 
        unsigned int ans = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            // Maintain a strictly increasing stack to find the Next Smaller Element
            while(!s.empty() && a[s.top()] >= a[i]) {
                s.pop();
            }
            
            if(s.empty()) {
                // If no smaller element exists to the right, a[i] is the minimum
                // for all (n - i) subarrays starting at i.
                dp[i] = (n - i) * a[i];
            } 
            else {
                int next_smaller_idx = s.top();
                // a[i] is the minimum for the subarrays stretching from i to next_smaller_idx - 1.
                // For subarrays extending beyond that, we reuse the pre-calculated sum starting at next_smaller_idx.
                dp[i] = (next_smaller_idx - i) * a[i] + dp[next_smaller_idx];
            }
            
            ans += dp[i];
            s.push(i);
        }
        
        // Safe to cast back to int based on problem constraints
        return ans; 
    }
};