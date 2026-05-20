class Solution {
  public:
    bool findTriplets(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=0;i<=n-3;i++){
            if(arr[i]>0) break;
            int target = -arr[i];
            int lo = i+1;
            int hi = n-1;
            while(lo<hi){
                if(arr[lo]+arr[hi]==target) return true;
                else if(arr[lo]+arr[hi]>target) hi--;
                else lo++;
            }
        }
        return false;
    }
};