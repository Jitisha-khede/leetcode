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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = head;
        if(head == NULL){
            return head;
        }
        while(head!=nullptr && head->val==val){
            head = head->next;
        }
        ListNode* curr = prev->next;
        while(curr!=NULL){
            if(curr->val == val){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        if(prev->val == val){
            return NULL;
            
        }
        return head;
    }
};