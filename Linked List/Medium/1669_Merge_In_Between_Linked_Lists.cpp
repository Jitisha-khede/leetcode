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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1->next;
        ListNode* prev = list1;
        int count=0;
        while(curr!=NULL){   
            if(count==a-1){
                prev->next = list2;
                prev = prev->next;
                break;
            }
            prev=curr;
            curr=curr->next;
            count++;
        }
        while(curr!=NULL && count!=b-1 ){
            curr=curr->next;
            count++;
        }
        while(list2->next!=NULL){
            list2=list2->next;
        }
        if(list2!=NULL) list2->next=curr->next;
        
        return list1;
    }
};