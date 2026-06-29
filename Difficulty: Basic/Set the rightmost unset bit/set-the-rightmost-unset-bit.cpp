class Solution {
  public:
    int setBit(int n) {
        // code here
        int x = n;
        int cnt = 0;
        while(x>0&&(x&1)){
            
            cnt++;
            x/=2;
        }
        return (1<<cnt) + n;
    }
};