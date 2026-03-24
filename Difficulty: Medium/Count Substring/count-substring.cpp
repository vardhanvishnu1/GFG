class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int n = s.size();
        int ans =0;
        int la = -1,lb=-1,lc=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a') la=i;
            else if(s[i]=='b') lb = i;
            else lc = i;
            if(la!=-1&&lb!=-1&&lc!=-1){
                ans+=(min({la,lb,lc}))+1;
            }
        }
        return ans;
    }
};