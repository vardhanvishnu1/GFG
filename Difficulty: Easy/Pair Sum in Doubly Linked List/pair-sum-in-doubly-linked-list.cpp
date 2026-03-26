// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int, int>>ans;
        Node* first = head;
        Node* second = head;
        while(second->next){
            second = second->next;
        }
        while(second!=first&&second->next!=first){
            if(first->data+second->data==target){
                ans.push_back({first->data,second->data});
                first = first->next;
            }
            else if(first->data+second->data>target){
                second = second->prev;
            }
            else first = first->next;
        }
        return ans;
    }
};