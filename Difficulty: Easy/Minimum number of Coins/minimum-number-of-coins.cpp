class Solution {
  public:
    int findMin(int n) {
        // code here
        int ans =0;
        while(n>=10){
            n-=10;ans++;
        }
        while(n>=5){
            n-=5;ans++;
        }
        while(n>=2){
            n-=2;ans++;
        }
        while(n>=1){
            n-=1;ans++;
        }
        return ans;
    }
};