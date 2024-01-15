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
   

    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next !=NULL && fast->next->next!=NULL){
            fast= fast->next->next;
            slow = slow->next;
        }
        if(fast->next!=NULL && fast->next->next==NULL) slow = slow->next;
        ListNode* prev = slow;
        ListNode* curr = slow;
        if(curr->next == NULL){
            head->next = NULL;
            return head;
        } 
        // return slow;
        else curr = curr->next;

        while(curr->next!=NULL){
            prev->val  = curr->val;
            prev = prev->next;
            curr = curr->next;
        }
        prev->val = curr->val;
        prev->next = NULL;
        return head;

        return slow;


    }
};