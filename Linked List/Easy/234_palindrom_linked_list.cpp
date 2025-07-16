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
//BRUTE FORCE
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> stack;
        ListNode* ptr=head;
        if(head == NULL || head->next == NULL) return true; 
        while(ptr != NULL){
            stack.push(ptr);
            ptr = ptr->next;
        }
        int len = stack.size()/2;
        ListNode* temp;
        while(len!=0){
            temp=stack.top();
            
            cout<<head->val<<" "<<temp->val<<endl;
            if(head->val!=temp->val){
                return false;
            }
            len--;
            head = head->next;
            stack.pop();
        }
        return true;
    }
};

//OPTIMAL
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* ptr = slow->next;
        ListNode* front = NULL;
        ListNode* prev = NULL;
        while(ptr!=NULL){
            front = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = front;
        }
        ListNode* first = head;
        ListNode* sec = prev;
        while(sec!=NULL){
            if(first->val!=sec->val) return false;
            sec=sec->next;
            first=first->next;
        }
        return true;
    }
};