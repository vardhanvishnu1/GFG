class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int lo =0;
        int hi = n-1;
        int mid;
        int mn = -1;
        int mn_val = INT_MAX;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(arr[lo]<=arr[mid]){
                if(mn_val>arr[lo]){
                    mn = lo;
                    mn_val = arr[lo];
                }
                lo = mid+1;
            }
            else{
                if(mn_val>arr[mid]){
                    mn = mid;
                    mn_val = arr[mid];
                }
                hi = mid-1;
            }
        }
        return mn;
    }
};
