class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        long long prev = 0;
        long long curr ;
        long long i = 0 ;
        while(1){
            curr=i*i;
            prev+=curr;
            if(prev>p) break;
            i++;
        }
        return i-1;
    }
};
