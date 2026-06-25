class Solution {
  public:
    void solve(int i,int x,int n,int cnt,vector<int>&ans){
        if(cnt==n){
            ans.push_back(x);
            return;
        }
        if(i>9) return;
        int j = (x%10)+1;
        while(j<=9){
            solve(j,x*10+j,n,cnt+1,ans);
            j++;
        }
    }
    vector<int> increasingNumbers(int n) {
        // code here
        vector<int>ans;
        if(n==1) ans.push_back(0);
        for(int i=1;i<=9;i++){
            solve(i,i,n,1,ans);
        }
        return ans;
    }
};