class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int i1 =0;
        int i2 =0;
        int n1 = a.size();
        int n2 = b.size();
        vector<int>ans;
        while(i1<n1&&i2<n2){
            if(a[i1]<=b[i2]){
                if(ans.size()>=1){
                    if(ans.back()==a[i1]) i1++;
                    else{
                    ans.push_back(a[i1]);
                    i1++;
                }
                }
                else{
                    ans.push_back(a[i1]);
                    i1++;
                }
            }
            else{
                if(ans.size()>=1){
                    if(ans.back()==b[i2]) i2++;
                    else{
                    ans.push_back(b[i2]);
                    i2++;
                }
                }
                else{
                    ans.push_back(b[i2]);
                    i2++;
                }
            }
        }
        while(i1<n1){
            if(ans.size()>=1){
                    if(ans.back()==a[i1]) i1++;
                    else{
                    ans.push_back(a[i1]);
                    i1++;
                }
                }
                else{
                    ans.push_back(a[i1]);
                    i1++;
                }
        }
        while(i2<n2){
            if(ans.size()>=1){
                    if(ans.back()==b[i2]) i2++;
                    else{
                    ans.push_back(b[i2]);
                    i2++;
                }
                }
                else{
                    ans.push_back(b[i2]);
                    i2++;
                }
        }
        return ans;
    }
};