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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* dummyHead = new ListNode(0);
        ListNode* front = dummyHead;
        int sum =0;
        while(curr!=NULL){
            sum=0;
            front->next = new ListNode(0);
            front = front->next;
            while(curr->val!=0){
                sum+=curr->val;
                curr=curr->next;
            }
            front->val = sum;    
            curr = curr->next;
        }
        dummyHead = dummyHead->next;
        return dummyHead;
    }
};