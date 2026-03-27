class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        int mask = 1<<k;
        return n&mask;
    }
};