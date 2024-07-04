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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL;
        ListNode* front = NULL;
        
        if(head==NULL) return head;
        if(left == right) return head;

        ListNode* lft = head;
        ListNode* rght = head;
        ListNode* temp = lft;
        ListNode* curr = NULL;

        if(left == 1){
            curr = head;
            for(int i=0;i<right;i++){
                front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }
            head->next = curr;
            return prev;
        }

        while(left>1){
            temp = lft;
            lft=lft->next;
            left--;
        }
        while(right>1){
            rght=rght->next;
            right--;
        }
        prev = lft;
        curr = lft->next;
        
        while(prev != rght && prev!=NULL){
            
            front = curr->next;
            curr->next = prev;
            prev= curr;
            curr = front; 

        }
        lft->next = front;
        temp->next = rght;

        return head;
    }
};