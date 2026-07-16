class Solution {
  public:
    int maxDiffSubArrays(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>lmin(n);vector<int>lmax(n);
        lmin[0] = arr[0];
        lmax[0] = arr[0];
        int sum = arr[0];
        for(int i=1;i<n;i++){
            sum = min(arr[i],sum+arr[i]);
            lmin[i] = min(sum,lmin[i-1]);
        }
        sum = arr[0];
        for(int i=1;i<n;i++){
            sum = max(arr[i],sum+arr[i]);
            lmax[i] = max(sum,lmax[i-1]);
        }
        vector<int>rmin(n);vector<int>rmax(n);
        rmin[n-1] = arr[n-1];
        rmax[n-1] = arr[n-1];
        sum=arr[n-1];
        for(int i=n-2;i>=0;i--){
            sum = min(arr[i],sum+arr[i]);
            rmin[i] = min(sum,rmin[i+1]);
        }
        sum = arr[n-1];
         for(int i=n-2;i>=0;i--){
            sum = max(arr[i],sum+arr[i]);
            rmax[i] = max(sum,rmax[i+1]);
        }
        int ans = INT_MIN;
        for(int i=1;i<n;i++){
            ans = max(ans,abs(rmax[i]-lmin[i-1]));
            ans = max(ans,abs(rmin[i]-lmax[i-1]));
        }
        return ans;
    }
};