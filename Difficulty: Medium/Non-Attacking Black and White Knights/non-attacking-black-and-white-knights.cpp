class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up = i+1;
                int down = max(0,n-2);
                int left = j+1;
                int right = max(0,m-2);
                ans+=m*n-1;
                if(i+2<n&&j+1<m) ans--;
                if(i+2<n&&j-1>=0) ans--;
                if(i-2>=0&&j+1<m) ans--;
                if(i-2>=0&&j-1>=0) ans--;
                
                if(i+1<n&&j+2<m) ans--;
                if(i-1>=0&&j+2<m) ans--;
                if(i+1<n&&j-2>=0) ans--;
                if(i-1>=0&&j-2>=0) ans--;
            }
        }
        return ans;
    }
};

// . . 
// . .