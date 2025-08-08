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
        ListNode* temp;
        ListNode* even = head->next;
        temp=even;
        ListNode* odd = head; 

        while(even!=NULL && odd!=NULL){
                if(even->next==NULL){
                    odd->next=temp;
                    return head;
                }
            
                odd->next=even->next;
                odd=odd->next;                
            
            if(odd!=NULL){
                even->next = odd->next;
                even=even->next;
            }
        }
        odd->next = temp;
        return head;
    }
};

//OPTIMAL

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
        ListNode* evenHead = head->next;
        ListNode* even = head->next;
        ListNode* odd = head;

        while((even!=NULL && even->next!=NULL)){
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};