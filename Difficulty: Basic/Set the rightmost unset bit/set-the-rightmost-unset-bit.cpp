class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        int x = n;
        int pos = 0;
        while(x>0){
            if(!(x&1)){
                break;
            }
            pos++;
            x>>=1;
        }
        int mask = 1<<pos;
        return mask|n;
    }
};