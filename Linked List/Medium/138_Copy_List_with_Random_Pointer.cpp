/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*,Node*> mp;
        Node* ptr = head;
        Node* dummy = new Node(0);
        Node* head2 = dummy;
        while(ptr!=NULL){
            dummy->val = ptr->val;
            if(ptr->next!=NULL)dummy->next = new Node(0);
            mp[ptr]=dummy;
            dummy = dummy->next;
            ptr = ptr->next;
        }

        Node* ptr2 = head2;
        for (auto it : mp) {
            if (it.first && it.first->random) {
                it.second->random = mp[it.first->random];
            } else {
                it.second->random = NULL;
            }
        }
        return head2;
    }
};