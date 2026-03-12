class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int n= arr.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,arr[i]);
        }
        return ans;
    }
};
