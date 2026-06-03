class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int n = s.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(s[i]=='0') ans[i] = 1;
            else ans[i] = -1;
        }
        int sum =0;
        int res =-1;
        for(int i=0;i<n;i++){
            sum+=ans[i];
            res = max(res,sum);
            if(sum<0) sum =0;
        }
        return res;
    }
};
