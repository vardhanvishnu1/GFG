class Solution {
  public:
    int countStrings(int n) {
        // code here
        int z = 0;
        int o = 2;
        int t = 3;
        if(n<=2) return n+1;
        int a[n+1];
        a[0]=0;a[1]=2;a[2]=3;
        for(int i=3;i<=n;i++){
            a[i] = a[i-1]+a[i-2];
        }
        return a[n];
    }
};