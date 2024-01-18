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
    ListNode *check(ListNode *fast,ListNode* slow){
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;

        }
        return slow;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast) return check(head,slow);
        }
        return NULL;

    }
};