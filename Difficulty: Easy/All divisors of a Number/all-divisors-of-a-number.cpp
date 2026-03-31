class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int>rem;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0)
            {
            cout<<i<<" ";
            int r = n/i;
            if(r!=i) rem.push_back(r);
            }
        }
        for(int i=rem.size()-1;i>=0;i--) {
            cout<<rem[i];
            if(i!=0) cout<<" ";
        }
    }
};