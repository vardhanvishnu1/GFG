class Solution {
  public:
    bool solve(vector<int>& arr, int k,int mid){
        int cnt =0;
        int mem =1;
        for(int i=0;i<arr.size();i++){
            cnt+=arr[i];
            if(cnt>mid){
                cnt = arr[i];
                mem++;
            }
            if(mem>k) return false;
        }
        return true;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int lo = *max_element(arr.begin(),arr.end());
        int hi = accumulate(arr.begin(),arr.end(),0);
        int mid;
        int ans = -1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(solve(arr,k,mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
    }
};