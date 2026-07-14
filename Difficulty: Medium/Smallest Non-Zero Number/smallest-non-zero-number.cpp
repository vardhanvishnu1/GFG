class Solution {
  public:
    int find(vector<int>& arr) {
        // code here
        long long ans = 0;
        for(int i=arr.size()-1;i>=0;i--){
            ans = (1+ans+arr[i]*1LL)/2;
        }
        return ans;
    }
};