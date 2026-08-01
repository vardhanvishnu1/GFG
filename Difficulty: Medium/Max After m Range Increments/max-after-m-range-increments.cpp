class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        int m = a.size();
        vector<int>dif(n+2,0);
        for(int i=0;i<m;i++){
            int st = a[i];
            int end = b[i]+1;
            int val = k[i];
            dif[st]+=val;
            dif[end]-=val;
        }
        int ans = dif[0];
        for(int i=1;i<n+2;i++){
            dif[i]+=dif[i-1];
            ans = max(ans,dif[i]);
        }
        return ans;
    }
};

/*
(0,1)-100 (1,4)-100 (2,3)-100

*/