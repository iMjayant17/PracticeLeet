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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode (0);
        ListNode* sm = small;
        ListNode* bg = big;
        while(head){
            if(head->val < x){
                sm->next = head;
                sm = sm->next;
            }
            else{
                bg->next = head;
                bg = bg->next;
            }
            head = head->next;
        }
        sm->next = big->next;
        bg->next = NULL;
        return small->next;

    }
};