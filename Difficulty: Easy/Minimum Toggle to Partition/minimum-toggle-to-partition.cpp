class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        if(arr[0]==1) pre[0]=1;
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+(arr[i]==1);
        }
        if(arr[n-1]==0) suf[n-1] = 1;
        for(int i = n-2;i>=0;i--){
            suf[i] = suf[i+1]+(arr[i]==0);
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,pre[i]+suf[i]);
        }
        return ans-1;
    }
};
// 1 1 2 3 3
// 2 2 1 1 1 