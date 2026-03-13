

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>post(n);
        post[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            post[i] = max(arr[i],post[i+1]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(arr[i]>=post[i]) ans.push_back(arr[i]);
        }
        return ans;
    }
};