class Solution {
public:
    // Use long long to prevent overflow
    long long getCost(vector<int>& heights, vector<int>& cost, int h) {
        long long totalCost = 0;
        for (int i = 0; i < heights.size(); i++) {
            totalCost += (long long)cost[i] * abs(heights[i] - h);
        }
        return totalCost;
    }

    long long minCost(vector<int>& heights, vector<int>& cost) {
        int lo = *min_element(heights.begin(), heights.end());
        int hi = *max_element(heights.begin(), heights.end());
        long long ans = getCost(heights, cost, lo);

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            long long cMid = getCost(heights, cost, mid);
            long long cNext = getCost(heights, cost, mid + 1);

            ans = min({ans, cMid, cNext});

            // If the cost is decreasing at mid, the minimum must be to the right
            if (cMid < cNext) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};