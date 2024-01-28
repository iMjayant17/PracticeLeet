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
    int len(ListNode* head){
        int cnt = 0;
        while(head){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0 ) return head;
        int h = len(head);
        k = k%h;
        if(k==0) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(k--){
            fast = fast->next;
        }
        ListNode* prev = slow;
        ListNode* prev1 = slow;

        while(fast->next!=NULL){
            fast = fast->next;
            prev = slow;
            
            slow = slow->next;
        }

        ListNode* ans = slow->next;
        slow->next = NULL;
        fast->next = head;
        return ans;

    }
};