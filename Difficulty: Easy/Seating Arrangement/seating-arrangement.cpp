class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n = seats.size();
        vector<int>used(n,false);
        for(int i=0;i<n;i++){
            if(i>0){
                if(seats[i]==1&&seats[i-1]==1) return false;
            }
            if(seats[i]==1){
                used[i] = true;
                if((i-1)>=0) used[i-1] = true;
                if((i+1)<n) used[i+1] = true;
            }
        }
        for(int i=0;i<n&&k>0;i++){
            if(!used[i]) {
                used[i] = true;
                k--;
                if((i-1)>=0) used[i-1] = true;
                if((i+1)<n) used[i+1] = true;
            }
        }
        return k==0;
    }
};