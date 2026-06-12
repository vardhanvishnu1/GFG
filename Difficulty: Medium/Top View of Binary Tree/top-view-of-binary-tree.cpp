class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root) return ans;

        map<int,int> mp;
        queue<pair<Node*,int>> q;

        q.push({root,0});

        while(!q.empty()){
            auto [node,hd] = q.front();
            q.pop();

            if(!mp.count(hd))
                mp[hd] = node->data;

            if(node->left)
                q.push({node->left,hd-1});

            if(node->right)
                q.push({node->right,hd+1});
        }

        for(auto &p : mp)
            ans.push_back(p.second);

        return ans;
    }
};