/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//BRUTE FORCE
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

//OPTIMAL
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dummy1 = headA;
        ListNode* dummy2 = headB;
        while(dummy1!=NULL || dummy2!=NULL){
            if(dummy1==dummy2) return dummy1;

            if(dummy1==NULL) {
                dummy1 = headB;
                continue;
            }
            if(dummy2==NULL){
                dummy2 = headA;
                continue;
            }

            dummy1=dummy1->next;
            dummy2=dummy2->next;
        }
        return NULL;
    }
};