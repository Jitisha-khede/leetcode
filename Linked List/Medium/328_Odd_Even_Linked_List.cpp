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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head->next;
        ListNode* even = dummy->next;
        ListNode* odd = head; 

        while(even!=NULL && odd!=NULL){
                if(even->next==NULL){
                    odd->next=dummy->next;
                    return head;
                }
            
                odd->next=even->next;
                odd=odd->next;                
            
            if(odd!=NULL){
                even->next = odd->next;
                even=even->next;
            }
        }
        odd->next = dummy->next;
        return head;
    }
};