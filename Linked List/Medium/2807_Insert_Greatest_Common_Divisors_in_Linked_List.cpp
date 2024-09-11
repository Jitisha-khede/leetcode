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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr=head;
        while(ptr->next!=NULL){
            int hcf = gcd(ptr->val, ptr->next->val);
            ListNode* l = new ListNode(hcf);
            l->next = ptr->next;
            ptr->next = l;
            if(ptr->next!=NULL) ptr = ptr->next->next;
        }
        return head;
    }
    int gcd(int a, int b){
        if(a==0) return b;
        return gcd(b%a,a);
    }
};