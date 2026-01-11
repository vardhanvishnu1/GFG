class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        // Use double for the ratio to avoid integer division truncation
        vector<pair<double, int>> v; 
        
        for(int i = 0; i < n; i++) {
            // Force double division by casting
            double ratio = (double)val[i] / wt[i];
            v.push_back({ratio, i});
        }
        
        // Sort by ratio (ascending by default)
        sort(v.begin(), v.end());
        
        double ans = 0;
        double remainingCapacity = (double)capacity;

        // Iterate backwards from the highest ratio
        for(int i = n - 1; i >= 0 && remainingCapacity > 0; i--) {
            int idx = v[i].second; // Get the original index of the item
            
            if(wt[idx] <= remainingCapacity) {
                // Take the whole item
                remainingCapacity -= wt[idx];
                ans += val[idx];
            } else {
                // Take the fraction that fits
                ans += v[i].first * remainingCapacity;
                remainingCapacity = 0;
            }
        }
        
        return ans;
    }
};