class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& nums) {
        //  code here
         stack<int>st;
        int n = nums.size();
        vector<int>ans(nums.size());
        for(int j=nums.size()-1;j>=0;j--){
                int i = j % n;
            while(!st.empty()&&st.top()>=nums[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            else ans[i] = -1;
            st.push(nums[i]);
        }
        return ans;
    }
};