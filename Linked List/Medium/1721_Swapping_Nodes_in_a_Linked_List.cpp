/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        curr=head;
        ListNode* front;
        for(int i=0;i<k-1;i++){
            curr=curr->next;
        }
        front=curr;
        curr=head;
        for(int i=0;i<count-k;i++){
            curr=curr->next;
        }
        int temp;
        temp = front->val;
        front->val = curr->val;
        curr->val = temp;
        return head;
    }
};