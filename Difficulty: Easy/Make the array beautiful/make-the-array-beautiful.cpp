class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        
        int n = arr.size();
        
        vector<int> st;
        
        for(int i = 0; i < n; i++){
            
            if(!st.empty()){
                
                int last = st.back();
                
                if((last >= 0 && arr[i] < 0) ||
                   (last < 0 && arr[i] >= 0)){
                    
                    st.pop_back();
                }
                else{
                    st.push_back(arr[i]);
                }
            }
            else{
                st.push_back(arr[i]);
            }
        }
        
        return st;
    }
};