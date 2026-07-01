class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n  = arr.size();
        if(n==1) return arr[0];
        vector<int>fk(n);
        vector<int>bk(n);
        fk[0] = arr[0];
        bk[n-1] = arr[n-1];
        for(int i=1;i<n;i++){
            fk[i] = max(arr[i],arr[i]+fk[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            bk[i] = max(arr[i],arr[i]+bk[i+1]);
        }
        int ans = *max_element(fk.begin(),fk.end());
        for(int i=1;i<n-1;i++){
            ans = max(ans,fk[i-1]+bk[i+1]);
        }
        ans = max(ans,fk[1]);
        ans = max(ans,bk[n-1]);
        return ans;
    }
};