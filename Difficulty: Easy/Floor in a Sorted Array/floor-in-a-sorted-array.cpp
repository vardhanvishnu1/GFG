class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int lo =0;
        int hi = n-1;
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(arr[mid]<=x) lo = mid+1;
            else hi = mid-1;
        }
        return hi;
    }
};
