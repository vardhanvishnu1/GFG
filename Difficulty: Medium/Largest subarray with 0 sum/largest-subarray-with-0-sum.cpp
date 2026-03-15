class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = arr[0];
        int ans = 0;
        if(sum==0) ans++;
        map<int,int>mp;
        mp[sum] = 0;
        for(int i=1;i<n;i++){
            sum+=arr[i];
            if(sum==0) ans = max(ans,i+1);
            if(mp.find(sum)!=mp.end()){
                ans = max(ans,i-mp[sum]);
            }
            if(mp.find(sum)==mp.end()) mp[sum] = i;
        }
        return ans;
    }
};