class Solution {
  public:
    int getCount(int n) {
        // code here
        // method 1
        // int mx = sqrt(n);
        // vector<int>a(n+1,false);
        // for(int i=1;i<=mx;i++){
        //     a[(i*(i+1))/2] = true;
        // }
        // int ans = 0;
        // for(int i=2;i<=mx;i++){
        //     if()
        // }
        // return ans;
        // method 2
        int ans = 0;
        
        for (long long k = 2; k * (k + 1) / 2 <= n; k++) {
            long long rem = n - k * (k - 1) / 2;

            if (rem > 0 && rem % k == 0)
                ans++;
        }

        return ans;
    }
};

