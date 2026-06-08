class Solution {
public:
    void solve(int idx, Node* root, vector<int>& suf) {
        if (!root) return;

        solve(idx + 1, root->next, suf);

        if (root->next)
            suf[idx] = max(root->data, suf[idx + 1]);
        else
            suf[idx] = root->data;
    }

    Node* compute(Node* head) {
        int n = 0;
        Node* temp = head;

        while (temp) {
            n++;
            temp = temp->next;
        }

        vector<int> suf(n);
        solve(0, head, suf);

        Node *curr = head, *prev = NULL;
        int idx = 0;

        while (curr) {
            if (curr->data < suf[idx]) {
                if (curr == head) {
                    head = head->next;
                    curr = head;
                } else {
                    prev->next = curr->next;
                    curr = prev->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
            idx++;
        }

        return head;
    }
};