class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int l =0;
        int r = 0;
        map<char,int>mp;
        int n = s.size();
        int ans =-1;
        while(r<n&&l<=r){
            mp[s[r]]++;
            while(mp.size()>k&&l<=r){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            if(mp.size()==k) ans = max(ans,r-l+1);
            r++;
        }
        if(mp.size()==k) ans = max(ans,r-l);
        return ans;
    }
};