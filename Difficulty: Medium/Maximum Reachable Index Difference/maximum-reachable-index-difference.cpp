class Solution {
  public:
    int maxIndexDifference(string &s) {
        // code here
        int n = s.size();
        int ans = INT_MIN;
        vector<int>v(26,-1);
        for(int i=0;i<n;i++){
            int ch = s[i]-'a';
            if(ch==0){
                if(v[0]==-1) v[0] = i;
                ans=max(ans,0);
            }
            else{
                if(v[ch-1]!=-1){
                    //v[ch] = min(v[ch],v[ch-1]);
                    v[ch]=0;
                    ans = max(ans,i-v[0]);
                }
            }
        }
        if(ans==INT_MIN) return -1;
        return ans;
        
        // vector<vector<int>>v(26,vector<int>(2,-1));
        // for(int i=0;i<n;i++){
        //     if(v[s[i]-'a'][0]==-1){
        //         v[s[i]-'a'][0]=i;
        //         v[s[i]-'a'][1]=i;
        //     }
        //     else{
        //         v[s[i]-'a'][1]=i;
        //     }
        // }
        
        // int ans =INT_MIN;
        // if(v[0][0]==-1) return -1;
        // int idx= 0;
        // for(int i=0;i<24;i++){
        //     if(v[i+1][0]==-1) break;
        //     if(v[i+1][1]<v[i][0]) break;
        //     if(v[i+1][0]<v[i][0]) v[i+1][0]=v[i+1][1];
        //     idx++;
        //     ans=max(ans,v[idx][1]-v[0][0]);
        // }
        // // if(ans==INT_MIN) return -1;
        // if(idx==0) return 0;
        
        // if(ans==INT_MIN) return -1;
        // return ans;
        
    }
};
