class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n==1) return;
        int prev = arr[0];
        arr[0] = arr[0]^arr[1];
        for(int i=1;i<n-1;i++){
            int x = arr[i];
            arr[i] = arr[i+1]^prev;
            prev = x;
        }
        arr[n-1] = arr[n-1]^prev;
    }
};