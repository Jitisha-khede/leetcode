/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        if(ptrA==NULL || ptrB == NULL){
            return NULL;
        }
        int lenA=0,lenB=0;
        while(ptrB!=NULL){
            lenB++;
            ptrB=ptrB->next;
        }
        while(ptrA!=NULL){
            lenA++;
            ptrA=ptrA->next;
        }   
        ptrA = headA;
        ptrB = headB;
        if(lenA>lenB){
            while(lenA-lenB!=0){
                lenA--;
                ptrA=ptrA->next;
                
            }
        }
        if(lenB>lenA){
            while(lenB-lenA!=0){
                lenB--;
                ptrB=ptrB->next;    
            }
        }   
        while(ptrA !=NULL && ptrB!=NULL){
            if(ptrA == ptrB){
                return ptrA;
            }
            ptrA= ptrA->next;
            ptrB= ptrB->next;
        }
        return NULL;
    }
};