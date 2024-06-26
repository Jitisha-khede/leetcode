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
    int getDecimalValue(ListNode* head) {
        int count = 0;
        ListNode* curr = head;
        if(head==NULL){
            return 0;
        }
        while(curr!=NULL){
            count++;
            curr = curr->next;
        }
        curr = head;
        count--;
        int integer=0;
        while(curr!=NULL){
            integer+=curr->val*pow(2,count);
            count--;
            curr = curr->next;
        }
        return integer;
    }
};