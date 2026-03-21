class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int lo =0;
        int hi = m;
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(pow(mid,n)==m) return mid;
            else if(pow(mid,n)>m) hi = mid-1;
            else lo = mid+1;
        }
        return -1;
    }
};