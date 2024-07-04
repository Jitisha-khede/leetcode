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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count =0;
        if(head==NULL){
            return NULL;
        }
        ListNode* curr = head;
        while(curr!=NULL){
            count++;
            curr = curr->next;
        }
        if(count==n){
            head=head->next;
            return head;
        }
        int temp = count-n;
        curr = head;
        ListNode* prev = NULL;
        while(temp!=0){
            prev = curr;
            curr = curr->next;
            temp--;
        }
        if(prev!=NULL && curr!=NULL){
            prev->next=curr->next;
        }
        
        return head;
    }
};