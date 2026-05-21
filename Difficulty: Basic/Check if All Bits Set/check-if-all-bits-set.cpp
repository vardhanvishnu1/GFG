class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0) return false;
        if(n==1) return true;
        int i =1;
        while(i<2*n){
            if(i-1==n) return true;
            i<<=1;
        }
        return false;
    }
};