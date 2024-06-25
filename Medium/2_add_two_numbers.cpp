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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        if(l1==NULL){
            return l2;
        }        
        if(l2==NULL){
            return l1;
        }
        
        ListNode* dummyHead = new ListNode(0);
        ListNode* sumNext = dummyHead;
        int carry = 0;
        while(l1!=NULL || l2!= NULL ){
            carry=0;

            if(l1!=NULL){
                sumNext->val = sumNext->val+l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sumNext->val = sumNext->val+l2->val;
                l2=l2->next;
            }
            if(sumNext->val>9){
                carry = sumNext->val/10; 
                sumNext->val= sumNext->val%10;
            }    
            if(carry==0 && !l1 && !l2){
                return dummyHead;
            }
            sumNext->next=new ListNode(0+carry);
            sumNext=sumNext->next;

        }
        if(!l1 && l2){
            sumNext->next = l2->next;
        }
        if(!l2 && l1){
            sumNext->next = l1->next;
        }
        return dummyHead;
    }
};