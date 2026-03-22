class Solution {
  public:
  bool canPlaceCows(const vector<int>& stalls, int k, int dist) {
        int cowsPlaced = 1;          // Place the first cow...
        int lastPos = stalls[0];     // ...in the first stall

        for (int i = 1; i < stalls.size(); i++) {
            // If the distance between the current stall and the last placed cow is >= dist
            if (stalls[i] - lastPos >= dist) {
                cowsPlaced++;        // Place another cow
                lastPos = stalls[i]; // Update the position of the last placed cow
                
                if (cowsPlaced == k) {
                    return true;     // Successfully placed all k cows
                }
            }
        }
        return false; // Ran out of stalls before placing all k cows
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        
        int n = stalls.size();
        
        // Step 2: Define the Binary Search space
        int lo = 1; 
        int hi = stalls[n - 1] - stalls[0];
        int result = -1;

        // Step 3: Binary Search on the Answer
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (canPlaceCows(stalls, k, mid)) {
                result = mid;    // This distance works! Save it.
                lo = mid + 1;    // But try to find a LARGER minimum distance
            } else {
                hi = mid - 1;    // This distance is too large, cows don't fit. Shrink the gap.
            }
        }

        return result;    
    }
};