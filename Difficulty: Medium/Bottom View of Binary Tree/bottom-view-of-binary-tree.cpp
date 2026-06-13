class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        map<int, int> mp; // hd -> node value
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();

            mp[hd] = node->data; // overwrite for bottom view

            if (node->left)
                q.push({node->left, hd - 1});

            if (node->right)
                q.push({node->right, hd + 1});
        }

        for (auto &it : mp)
            ans.push_back(it.second);

        return ans;
    }
};