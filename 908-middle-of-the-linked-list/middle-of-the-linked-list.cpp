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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = fast;



        // if(fast==NULL) return NULL;

        // if(fast->next == NULL) return fast;

        // if(fast->next->next==NULL) return slow->next;

        while(fast !=NULL && (fast->next )!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // if(fast->next!=NULL && fast->next->next==NULL) return slow->next;
        return slow;
    }
};