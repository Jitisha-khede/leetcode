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

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* end = head;
        ListNode* prev = NULL;
        if(head==NULL || k==0 || head->next==NULL){
            return head;
        }
        int count = 0;
        while(end!=NULL){
            count++;
            end=end->next;
        }
        end=head;
        if(k>count){
            k = k % count;
        }
        while(k--){
            while(end!=NULL){
                if(end->next==NULL){
                    break;
                }
                prev=end;
                end=end->next;
            }
            end->next = head;
            prev->next = NULL;
            head = end;
            end = head;
        }
        return head; 
    }
};