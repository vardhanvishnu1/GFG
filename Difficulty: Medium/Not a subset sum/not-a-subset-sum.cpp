class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans = 1;
        for(int i=0;i<n&&arr[i]<=ans;i++){
            ans+=arr[i];
        }
        return ans;
    }
};