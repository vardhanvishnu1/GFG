class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int ans =0;
        vector<int>pre(n,0);
        pre[0] = arr[0];
        if(pre[0]==k) ans = 1;
        map<int,int>mp;
        mp[pre[0]] = 0;
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+arr[i];
            if(pre[i]==k) ans = max(ans,i+1);
            int x = pre[i] - k;
            if(mp.find(x)!=mp.end()){
                ans = max(ans,i-mp[x]);
            }
            if(mp.find(pre[i])==mp.end()) mp[pre[i]] = i;
        }
        
        return ans;
    }
};