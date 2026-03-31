class Solution {
  public:
    int largestPrimeFactor(int n) {
        // code here
        int maxPrime = -1;
        int x = n;
        while(n%2==0){
            maxPrime=2;
            n/=2;
        }
        for(int i=3;i<=sqrt(n);i+=2){
            while(n%i==0){
                maxPrime = i;
                n/=i;
            }
        }
        if(n>2) return n;
        return maxPrime;
    }
};