class Solution {
  public:
    int countSubstring(string &s) {
        // Code here
        int n = s.size();
        int ans =0;
        int l =0;
        int r = 0;
        map<int,int>freq;
        while(r<n){
            freq[s[r]-'a']++;
            
            while(freq.size()==3){
                if(freq.size()==3) ans+=(n-r);
                freq[s[l]-'a']--;
                if(freq[s[l]-'a']==0) freq.erase(s[l]-'a');
                l++;
            }
            r++;
        }
        return ans;
    }
};