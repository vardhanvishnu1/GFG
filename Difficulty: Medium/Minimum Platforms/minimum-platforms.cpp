class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int ans = 0;
        int i1 = 0;
        int i2 = 0;
        int cnt = 0;
        while(i1<n&&i2<n){
            if(arr[i1]<=dep[i2]) {cnt++;i1++;}
            else{
                cnt--;i2++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
