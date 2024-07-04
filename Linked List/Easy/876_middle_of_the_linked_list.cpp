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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int count = 0;
        if(head==NULL){
            return head;
        }
        while(curr != NULL){
            count++;
            curr = curr->next;
        }     
        count/=2;
        while(count){
            head = head->next;
            count--;
        }
        return head;
    }
};