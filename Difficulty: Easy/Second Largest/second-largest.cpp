class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        for(int i=0;i<n;i++){
            if(mx1==INT_MIN) mx1 = arr[i];
            else if(arr[i]<mx1){
                mx2 = max(mx2,arr[i]);
            }
            else if(arr[i]>mx1){
                swap(mx1,mx2);
                mx1 = arr[i];
            }
        }
        if(mx2==INT_MIN) return -1;
        return mx2;
    }
};