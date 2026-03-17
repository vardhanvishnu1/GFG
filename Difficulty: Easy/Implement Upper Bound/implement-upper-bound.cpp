class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n= arr.size();
        int lo =0;
        int hi = n-1;
        int mid ;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(arr[mid]<=target){
                lo = mid+1;
                
            }
            else hi = mid-1;
        }
        return lo;
    }
};
