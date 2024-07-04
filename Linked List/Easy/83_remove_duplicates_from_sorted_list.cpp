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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = head;
 
        if(head==NULL){
            return head;
        }
        ListNode* curr = prev->next;
        while(curr!= NULL){
            if(curr->val == prev->val){
                prev->next = curr->next;    
                curr = curr->next;
            }else{
                prev = curr;
                curr = curr->next;
            }    
        }
        return head;
    }
};