class Solution {
  public:
  long long memo[51][51];
  long long solve(long long  sum,long long  cnt,long long  n,long long  m,long long  x){
      if(cnt>n) return 0;
      if(cnt==n){ 
          if(sum==x) return 1;
          else return 0;
      }
      if(sum>=x) return 0;
      if(memo[sum][cnt]!=-1) return memo[sum][cnt];
        long long  ways = 0;
      for(long long  i=1;i<=m;i++){
          ways+= solve(sum+i,cnt+1,n,m,x);
      }
      return memo[sum][cnt] = ways;
  }
    int noOfWays(int m, int n, int x) {
        for(int i=0;i<51;i++){
            for(int j=0;j<51;j++){
            memo[i][j] = -1;
        }
        }
        // code here
        long long  ans =0;
        for(long long  i=1;i<=m;i++){
            ans+=solve(i,1,n,m,x);
        }
        return ans;
    }
};