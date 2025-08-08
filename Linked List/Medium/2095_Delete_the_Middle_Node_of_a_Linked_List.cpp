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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;
        ListNode* curr = head;
        if(head == NULL || head->next==NULL){
            return NULL;
        }
        while(curr!=NULL){
            count++;
            curr = curr->next;
        }
        curr=head;
        count/=2;
        ListNode* prev = NULL;
        while(count--&&curr!=NULL){
            prev= curr;
            curr=curr->next;
        }
        prev->next = curr->next;
        return head;
    }
};
// OPTIMAL
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return head;
    }
};