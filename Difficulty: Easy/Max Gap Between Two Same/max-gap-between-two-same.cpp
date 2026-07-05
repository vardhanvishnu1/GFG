class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int n = s.size();
        unordered_map<char,int>mp1;unordered_map<char,int>mp2;
        for(int i=0;i<s.size();i++){
            if(!mp1.count(s[i])){
                mp1[s[i]] = i;
            }
            else{
                mp2[s[i]] = i;
            }
        }
        int ans = -1;
        for(auto el : mp1){
            char ch = el.first;
            int curr = mp2[ch]-el.second-1;
            if(!mp2.count(ch)) continue;
            ans = max(ans,curr);
        }
        return ans;
    }
};